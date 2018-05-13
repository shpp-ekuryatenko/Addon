#include <node.h>
#include <v8.h>
#include <uv.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace v8;

struct Work {
  uv_work_t  request;
  Persistent<Function> callback;
  int delayValue;
};

// called by libuv worker in separate thread
static void WorkAsync(uv_work_t *req)
{
    Work *work = static_cast<Work *>(req->data);

    std::cout << "From WorkAsync" << std::endl;

    // that wasn't really that long of an operation, so lets pretend it took longer...
    std::this_thread::sleep_for(std::chrono::seconds(work->delayValue));
}

// called by libuv in event loop when async function completes
static void WorkAsyncComplete(uv_work_t *req,int status)
{
    Isolate * isolate = Isolate::GetCurrent();
    std::cout << "From WorkAsyncComplete" << std::endl;
    // Fix for Node 4.x - thanks to https://github.com/nwjs/blink/commit/ecda32d117aca108c44f38c8eb2cb2d0810dfdeb
    v8::HandleScope handleScope(isolate);

    //Local<Array> result_list = Array::New(isolate);
    Work *work = static_cast<Work *>(req->data);

    // execute the callback
    // https://stackoverflow.com/questions/13826803/calling-javascript-function-from-a-c-callback-in-v8/28554065#28554065
    Local<Function>::New(isolate, work->callback)->Call(isolate->GetCurrentContext()->Global(), 0, NULL);

    // Free up the persistent function callback
    work->callback.Reset();
    delete work;
}

void DelayAsync(const v8::FunctionCallbackInfo<v8::Value>&args) {
    Isolate* isolate = args.GetIsolate();

    Work * work = new Work();
    work->request.data = work;

    
    // Store delay value in seconds for Delay function
    int delay  = args[0]->NumberValue();
	work->delayValue = delay;
	// store the callback from JS in the work package so we can
    // invoke it later
    Local<Function> callback = Local<Function>::Cast(args[1]);
    work->callback.Reset(isolate, callback);


    // kick of the worker thread
    uv_queue_work(uv_default_loop(),&work->request,WorkAsync,WorkAsyncComplete);

    args.GetReturnValue().Set(Undefined(isolate));
}

void init(Handle <Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(exports, "delay", DelayAsync);
}

NODE_MODULE(rainfall, init)