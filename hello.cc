#include <napi.h>
#include <stdio.h>

Napi::Value Print(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	
	printf("Hello, world \n");
	return Napi::String::New(env, "Hello, world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "print"),
				Napi::Function::New(env, Print));
	return exports;
}

NODE_API_MODULE(hello, Init)
