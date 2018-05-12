#include <node.h>
#include <iostream>

namespace demo {

using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Print(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	
	String::Utf8Value s (args[0]->ToString());
	std::string str(*s);
	str = str + "!!!!";
	
	Local<String> ret = String::NewFromUtf8(isolate, str.c_str());
	args.GetReturnValue().Set(ret);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "print", Print);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace demo
