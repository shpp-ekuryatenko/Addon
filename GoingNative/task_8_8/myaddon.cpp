#include "node.h"
#include "v8.h"
#include <iostream>
#include "nan.h"
#include <windows.h>

using namespace v8 ;

// A worker class extending the NanAsyncWorker helper
// class, a simple encapsulation of worker-thread
// logic to make simple tasks easier

class MyWorker : public Nan::AsyncWorker {
 public:
  // Constructor
  MyWorker(Nan::Callback *callback, int delay)
    : Nan::AsyncWorker(callback), delay(delay) {}
  // Destructor
  ~MyWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access V8, or V8 data structures
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute () {
    // Asynchronous, non-V8 work goes here
	//std::cout << "DELAY";
	Sleep(delay);
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use V8 again
  void HandleOKCallback () {
    Nan::HandleScope scope;
	//std::cout << "HandleOKCallback";
    // Nan::Callback#Call() does a Nan::MakeCallback() for us
    callback->Call(0, NULL);
  }

 private:
  int delay;
};

NAN_METHOD(Delay) {
  // get delay and callback
  // create NanCallback instance wrapping the callback
  // create a MyWorker instance, passing the callback and delay
  // queue the worker instance onto the thread-pool
  
  
  // Check the number of arguments passed.
  if ( info.Length() != 2 ) {
    return Nan::ThrowError(Nan::New("expected 2 arguments").ToLocalChecked());
  }

  // Check the argument types
  if ( !info[0]->IsNumber() ) {
    return Nan::ThrowError(Nan::New("expected arg 1: as delay number").ToLocalChecked());
  }
  
  if(!info[1]->IsFunction()) {
    return Nan::ThrowError(Nan::New("expected arg 2: function callback").ToLocalChecked());
  }
  
  // Perform the operation
  int delay = info[0]->NumberValue();
  
  Nan::Callback* nanCallback = new Nan::Callback(info[1].As<v8::Function>());
  
  MyWorker* worker = new MyWorker(nanCallback, delay);
  
  // starting the async worker
  Nan::AsyncQueueWorker(worker);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New("delay").ToLocalChecked(),
      Nan::GetFunction(Nan::New<FunctionTemplate>(Delay)).ToLocalChecked());
}

NODE_MODULE(myaddon, Init)

