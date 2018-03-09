#include <node.h>
using namespace v8;

void CallThis(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  //the Call method accepts three parameters:
  // 1) Receiver - JS object that 'this' will be bound to when the JS
  // callback is invoked. Setting to null will just set 'this' to whatever
  // the default is within the JS code
  // 2) Number of Args - number of params to pass to callback when executed
  // 3) Arguments - null in this case, but can pass an array of Local<Value> objects

/*   NOT WORKED: cannot convert argument 3 from 'v8::Local<v8::Array>' to 'v8::Local<v8::Value> []'
  Local<Array> array = Array::New(isolate);
  Handle<Value> array = Array::New(isolate);
  array->Set(0, Number::New(isolate, 1000));
  Local<Value> retval = v8::Number::New(isolate, 121);
  array->Set(0, retval);*/

  Local<Function> cb = Local<Function>::Cast(args[0]);

  Handle<Value> array[1];
  array[0] = v8::Number::New(isolate, 121);

  cb->Call(Null(isolate), 1, array);
  return;   //undefined is returned to JS
}

//called when function is require'd in JS
void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "callThis", CallThis);
}

NODE_MODULE(callback, Init)   //macro