{
	"targets": [
	{
		"target_name": "calculator",
		"cflags!": [ "-fno-exceptions" ],
		"cflags_cc!": [ "-fno-exceptions" ],
		"sources": [ "calculator.cc", "gen/bacardi.cc", "gen/calculator_bridge.cc" ],
		"include_dirs": ["<!@(node -p \"require('node-addon-api').include\")",
		                 "<!@(node -p \"require('node-addon-api').include_bacardi\")"],
		"dependencies": ["<!(node -p \"require('node-addon-api').gyp\")",
	                     "<!(node -p \"require('node-addon-api').gyp_bacardi\")"],
		'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
	}]
}
