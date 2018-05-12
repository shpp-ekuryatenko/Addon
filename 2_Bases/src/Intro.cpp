#include <node.h>;
#include <v8.h>;

using namespace v8;

Persistent <Object> persist;

void InitPersisit(const v8::FunctionCallbackInfo<v8::Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Object> obj = Object::New(isolate);
  obj->Set(String::NewFromUtf8(isolate,"cnt"), Number::New(isolate, 0));
  persist.Reset(isolate, obj);
}

void ReturnCnt(const v8::FunctionCallbackInfo<v8::Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Object> target = Local<Object>::New(isolate, persist);
  args.GetReturnValue().Set(target);
}

void incrementPersist(Isolate * isolate, const v8::FunctionCallbackInfo<v8::Value>& args) {
  Local<Object> target = Local<Object>::New(isolate, persist);
  Handle<Value> cnt_Value = target->Get(String::NewFromUtf8(isolate,"cnt"));
  int cnt = cnt_Value->NumberValue();
  target->Set(String::NewFromUtf8(isolate,"cnt"), Number::New(isolate, ++cnt));
  /*persist.Reset(isolate, target);*/
}

void MyNum(const v8::FunctionCallbackInfo<v8::Value> & args) {
  Isolate* isolate = args.GetIsolate();
  incrementPersist(isolate, args);
  Local<Number> retval = v8::Number::New(isolate, 121);
  args.GetReturnValue().Set(retval);
}

void MyUnpack(const v8::FunctionCallbackInfo<v8::Value>& args) {
  Isolate* isolate = args.GetIsolate();

  double avg = args[0]->NumberValue();
  avg = avg / 3;
  incrementPersist(isolate, args);
  Local<Number> retval = v8::Number::New(isolate, avg);
  args.GetReturnValue().Set(retval);
}

void MyObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Handle<Object> js_obj = Handle<Object>::Cast(args[0]);
  Handle<Value> obj_Value = js_obj->Get(String::NewFromUtf8(isolate,"x"));
  double return_Value = obj_Value->NumberValue();
  Local<Number> retval = v8::Number::New(isolate, return_Value * 2);
  incrementPersist(isolate, args);
  args.GetReturnValue().Set(retval);
}

//Return double sum of all array elements
void DoubleArray(const v8::FunctionCallbackInfo<v8::Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Array> array = Local<Array>::Cast(args[0]);

  double sum = 0;
  for(unsigned int i = 0; i < array->Length(); i++ ){
    double value = array->Get(i)->NumberValue();
    sum += value;
  }
  incrementPersist(isolate, args);
  Local<Number> retval = v8::Number::New(isolate, sum*2);
  args.GetReturnValue().Set(retval);
}

//Modify every Array element
void ModifyOn2Array(const v8::FunctionCallbackInfo<v8::Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Array> array = Local<Array>::Cast(args[0]);
  Local<Array> array2 = Array::New(isolate);

  for(unsigned int i = 0; i < array->Length(); i++ ){
    double value = array->Get(i)->NumberValue();
    array->Set(i, Number::New(isolate, value*2));
    array2->Set(i, Number::New(isolate, value*2));
  }
  incrementPersist(isolate, args);
  args.GetReturnValue().Set(array2);
}

void init(Handle <Object> exports, Handle<Object> module) {
 NODE_SET_METHOD(exports, "MyNum", MyNum);
 NODE_SET_METHOD(exports, "unpack", MyUnpack);
 NODE_SET_METHOD(exports, "handleObj", MyObj);
 NODE_SET_METHOD(exports, "doubleArray", DoubleArray);
 NODE_SET_METHOD(exports, "on2Array", ModifyOn2Array);
 NODE_SET_METHOD(exports, "init", InitPersisit);
 NODE_SET_METHOD(exports, "getCnt", ReturnCnt);

}

// associates the module name with initialization logic
NODE_MODULE(intro, init);