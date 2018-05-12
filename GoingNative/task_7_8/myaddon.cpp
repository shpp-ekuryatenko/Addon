#include <node.h>
#include <v8.h>
#include <iostream>
#include <windows.h>
//#include <cstring>

using namespace v8 ;

void Delay(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Function> cb = Local<Function>::Cast(args[1]);
  
  // Check the number of arguments passed.
  if ( args.Length() != 2 ) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  // Check the argument types
  if ( !args[0]->IsNumber() ) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }
  
  // Perform the operation
  int value = args[0]->NumberValue();
  
  Sleep(value);
  
  cb->Call(Null(isolate),  0, NULL);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "delay", Delay);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

