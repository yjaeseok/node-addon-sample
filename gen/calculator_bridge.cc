/**
 * Copyright (c) 2017 The Bacardi Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "calculator_bridge.h"

#include <js_type_traits.h>
#include <native_type_traits.h>
#include <enum_validator.h>

void CalculatorBridge::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function js_constructor =
      DefineClass(env, "Calculator",
                  {
                    StaticMethod("print", &CalculatorBridge::Print),
                    InstanceMethod("add", &CalculatorBridge::Add),
                    InstanceMethod("sub", &CalculatorBridge::Sub),
                    InstanceMethod("mul", &CalculatorBridge::Mul),
                    InstanceMethod("div", &CalculatorBridge::Div),
                    InstanceMethod("isEquals", &CalculatorBridge::IsEquals),
                    InstanceMethod("calculate", &CalculatorBridge::Calculate),
                    });
  exports.Set("Calculator", js_constructor);
}

CalculatorBridge::CalculatorBridge(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<CalculatorBridge>(info) {
  int argumentLength = info.Length();
  if (4 == 0 && argumentLength == 0) {
    impl_.reset(new Calculator ());
    return;
  }
   
  // FIXME(yjaeseok): This if statement needs to apply optimization.
  if (argumentLength == 0) {
    
    impl_.reset(new Calculator());
    return;
  } 
  // FIXME(yjaeseok): This if statement needs to apply optimization.
  if (argumentLength == 1 
      && NativeTypeTraits<IDLLong>::IsTypeEquals(info[0])) {
    auto createdTime = NativeTypeTraits<IDLLong>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return;
}
    impl_.reset(new Calculator(createdTime));
    return;
  } 
  // FIXME(yjaeseok): This if statement needs to apply optimization.
  if (argumentLength == 2 
      && NativeTypeTraits<IDLLong>::IsTypeEquals(info[0]) 
      && NativeTypeTraits<IDLLong>::IsTypeEquals(info[1])) {
    auto arg1 = NativeTypeTraits<IDLLong>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return;
}auto arg2 = NativeTypeTraits<IDLLong>::NativeValue(info.Env(), info[1]);
if (info.Env().IsExceptionPending()) {
  return;
}
    impl_.reset(new Calculator(arg1, arg2));
    return;
  } 
  // FIXME(yjaeseok): This if statement needs to apply optimization.
  if (argumentLength == 2 
      && NativeTypeTraits<IDLString>::IsTypeEquals(info[0]) 
      && NativeTypeTraits<IDLString>::IsTypeEquals(info[1])) {
    auto msg1 = NativeTypeTraits<IDLString>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return;
}auto msg2 = NativeTypeTraits<IDLString>::NativeValue(info.Env(), info[1]);
if (info.Env().IsExceptionPending()) {
  return;
}
    impl_.reset(new Calculator(msg1, msg2));
    return;
  }

  Napi::Error::New(info.Env(), "There is no valid constructor.")
      .ThrowAsJavaScriptException();
}Napi::Value CalculatorBridge::Print(const Napi::CallbackInfo& info) {
  if (info.Length() != 1) {
    Napi::RangeError::New(info.Env(), "Wrong number of arguments.")
        .ThrowAsJavaScriptException();
    return Napi::Value();
  }

  auto message = NativeTypeTraits<IDLString>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}

  
  Calculator::Print(message);
  return Napi::Value();
}

Napi::Value CalculatorBridge::Add(const Napi::CallbackInfo& info) {
  if (info.Length() != 2) {
    Napi::RangeError::New(info.Env(), "Wrong number of arguments.")
        .ThrowAsJavaScriptException();
    return Napi::Value();
  }

  auto number1 = NativeTypeTraits<IDLLong>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}auto number2 = NativeTypeTraits<IDLLong>::NativeValue(info.Env(), info[1]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}

  auto return_value =
  impl_->Add(number1, number2);
  return JSTypeTraits(info.Env(), return_value);
}

Napi::Value CalculatorBridge::Sub(const Napi::CallbackInfo& info) {
  if (info.Length() != 2) {
    Napi::RangeError::New(info.Env(), "Wrong number of arguments.")
        .ThrowAsJavaScriptException();
    return Napi::Value();
  }

  auto number1 = NativeTypeTraits<IDLShort>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}auto number2 = NativeTypeTraits<IDLShort>::NativeValue(info.Env(), info[1]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}

  auto return_value =
  impl_->Sub(number1, number2);
  return JSTypeTraits(info.Env(), return_value);
}

Napi::Value CalculatorBridge::Mul(const Napi::CallbackInfo& info) {
  if (info.Length() != 2) {
    Napi::RangeError::New(info.Env(), "Wrong number of arguments.")
        .ThrowAsJavaScriptException();
    return Napi::Value();
  }

  auto number1 = NativeTypeTraits<IDLDouble>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}auto number2 = NativeTypeTraits<IDLDouble>::NativeValue(info.Env(), info[1]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}

  auto return_value =
  impl_->Mul(number1, number2);
  return JSTypeTraits(info.Env(), return_value);
}

Napi::Value CalculatorBridge::Div(const Napi::CallbackInfo& info) {
  if (info.Length() != 2) {
    Napi::RangeError::New(info.Env(), "Wrong number of arguments.")
        .ThrowAsJavaScriptException();
    return Napi::Value();
  }

  auto number1 = NativeTypeTraits<IDLDouble>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}auto number2 = NativeTypeTraits<IDLDouble>::NativeValue(info.Env(), info[1]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}

  auto return_value =
  impl_->Div(number1, number2);
  return JSTypeTraits(info.Env(), return_value);
}

Napi::Value CalculatorBridge::IsEquals(const Napi::CallbackInfo& info) {
  if (info.Length() != 2) {
    Napi::RangeError::New(info.Env(), "Wrong number of arguments.")
        .ThrowAsJavaScriptException();
    return Napi::Value();
  }

  auto number1 = NativeTypeTraits<IDLShort>::NativeValue(info.Env(), info[0]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}auto number2 = NativeTypeTraits<IDLShort>::NativeValue(info.Env(), info[1]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}

  auto return_value =
  impl_->IsEquals(number1, number2);
  return JSTypeTraits(info.Env(), return_value);
}

Napi::Value CalculatorBridge::Calculate(const Napi::CallbackInfo& info) {
  if (info.Length() != 3) {
    Napi::RangeError::New(info.Env(), "Wrong number of arguments.")
        .ThrowAsJavaScriptException();
    return Napi::Value();
  }

  const std::set<std::string> enum_value_set = {
    "add",
    "sub",
    "mul",
    "div",
    };

auto type = NativeTypeTraits<IDLString>::NativeValue(info.Env(), info[0]);
if (!EnumValidator::isValildEnum(type, enum_value_set)) {
  Napi::TypeError::New(info.Env(), "it not matched with values of enum in idl.")
      .ThrowAsJavaScriptException();
  return Napi::Value();
}
auto number1 = NativeTypeTraits<IDLDouble>::NativeValue(info.Env(), info[1]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}auto number2 = NativeTypeTraits<IDLDouble>::NativeValue(info.Env(), info[2]);
if (info.Env().IsExceptionPending()) {
  return Napi::Value();
}

  auto return_value =
  impl_->Calculate(type, number1, number2);
  return JSTypeTraits(info.Env(), return_value);
}


