#include <napi.h>
#include "calculator_bridge.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	  CalculatorBridge::Init(env, exports);
	    return exports;
}

NODE_API_MODULE(bacardi, Init);
