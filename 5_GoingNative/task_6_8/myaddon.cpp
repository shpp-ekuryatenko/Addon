#include <node.h>
#include <v8.h>
#include <iostream>
//#include <cstring>

using namespace v8 ;

void Length(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	
	String::Utf8Value s (args[0]->ToString());
	std::string str(*s);
  
	int value = str.size();
	Local<Number> ret = Number::New(isolate, value);
	
	args.GetReturnValue().Set(ret);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "length", Length);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

