/* 
Async
https://nodesource.com/blog/cpp-addons-for-nodejs-v4
Qt Threads - moveToThread, start
Medium - https://medium.com/@muehler.v/tutorial-to-native-node-js-df4118efb678
https://softwareengineeringdaily.com/2015/08/02/how-does-node-js-work-asynchronously-without-multithreading/
https://jsblog.insiderattack.net/handling-io-nodejs-event-loop-part-4-418062f917d1
https://jsblog.insiderattack.net/event-loop-and-the-big-picture-nodejs-event-loop-part-1-1cb67a182810
https://github.com/justadudewhohacks/node-addon-tutorial/blob/master/VectorExample/src/Vector.cc



*/


#include <node.h>
#include <iostream>
#include <nan.h>

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


/* 
Async
https://nodesource.com/blog/cpp-addons-for-nodejs-v4
Qt Threads - moveToThread, start
Medium - https://medium.com/@muehler.v/tutorial-to-native-node-js-df4118efb678
https://softwareengineeringdaily.com/2015/08/02/how-does-node-js-work-asynchronously-without-multithreading/
https://jsblog.insiderattack.net/handling-io-nodejs-event-loop-part-4-418062f917d1
https://jsblog.insiderattack.net/event-loop-and-the-big-picture-nodejs-event-loop-part-1-1cb67a182810
https://github.com/justadudewhohacks/node-addon-tutorial/blob/master/VectorExample/src/Vector.cc



*/