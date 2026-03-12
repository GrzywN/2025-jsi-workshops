#include "NativeJSIWorkshopsModule.h"

#include "host-objects/DateHostObject.h"
#include "host-objects/InfinityHostObject.h"
#include "native-states/NativeStateCounter.h"

namespace facebook::react {

NativeJSIWorkshopsModule::NativeJSIWorkshopsModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeJSIWorkshopsModuleCxxSpec(std::move(jsInvoker)) {}

void NativeJSIWorkshopsModule::install(jsi::Runtime &rt) {
  task1(rt);
  task2(rt);
  task3(rt);
  task4(rt);
  task5(rt);
  task6(rt);
  task7(rt);
  task8(rt);
  task9(rt);
  task10(rt);
  task11(rt);
  task12(rt);
  task13(rt);
  task14(rt);
}

void NativeJSIWorkshopsModule::task1(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "answerToTheUltimateQuestionOfLifeTheUniverseAndEverything";
  jsi::Value value = jsi::Value(42);

  rt.global().setProperty(rt, propertyName, value);
}

void NativeJSIWorkshopsModule::task2(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "isWednesday";
  jsi::Value value = jsi::Value(false);

  rt.global().setProperty(rt, propertyName, value);
}

void NativeJSIWorkshopsModule::task3(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "workshopsName";

  std::string string = "App.js";
  jsi::Value value = jsi::String::createFromUtf8(rt, string);

  rt.global().setProperty(rt, propertyName, value);
}

void NativeJSIWorkshopsModule::task4(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "myAwesomeArray";
  jsi::Value value = jsi::Array::createWithElements(
      rt, {jsi::Value(42), jsi::Value(true), jsi::String::createFromAscii(rt, "App.js")});

  rt.global().setProperty(rt, propertyName, value);

  // jsi::Array arrayValue(rt, 3);
  // arrayValue.setValueAtIndex(rt, 0, 42);
  // arrayValue.setValueAtIndex(rt, 1, true);
  // arrayValue.setValueAtIndex(rt, 2, "App.js");
  // rt.global().setProperty(rt, propertyName, std::move(arrayValue));
}

void NativeJSIWorkshopsModule::task5(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "giveMeFive";
  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      0,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        return jsi::Value(5);
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task6(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "sumMeThis";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      2,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        double a = args[0].asNumber();
        double b = args[1].asNumber();

        return jsi::Value(a + b);
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task7(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "divideMeThis";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      2,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        double a = args[0].asNumber();
        double b = args[1].asNumber();

        if (b == 0) {
          throw jsi::JSError(rt, std::format("[{}] Division by zero", propertyName));
        }

        return jsi::Value(a / b);
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task8(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "reverseMeThis";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      1,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        std::string s = args[0].asString(rt).utf8(rt);
        std::reverse(s.begin(), s.end());

        return jsi::String::createFromUtf8(rt, s);
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task9(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "sumMeThisObject";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      1,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        const jsi::Object &object = args[0].asObject(rt);
        double a = object.getProperty(rt, "firstNum").asNumber();
        double b = object.getProperty(rt, "lastNum").asNumber();

        return jsi::Value(a + b);
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task10(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "sumMeThisArray";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      1,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        const jsi::Array &arr = args[0].asObject(rt).asArray(rt);

        double sum = 0;
        size_t arraySize = arr.size(rt);

        for (size_t i = 0; i < arraySize; i++) {
          sum += arr.getValueAtIndex(rt, i).asNumber();
        }

        return jsi::Value(sum);
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task11(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "nativeMap";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      2,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        const jsi::Array &arr = args[0].asObject(rt).asArray(rt);
        const jsi::Function &fn = args[1].asObject(rt).asFunction(rt);

        size_t arraySize = arr.size(rt);
        jsi::Array copy(rt, arraySize);

        for (size_t i = 0; i < arraySize; i++) {
          copy.setValueAtIndex(rt, i, fn.call(rt, arr.getValueAtIndex(rt, i)));
        }

        return copy;
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task12(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "runJsFunction";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      0,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        jsi::Object console = rt.global().getPropertyAsObject(rt, "console");
        jsi::Function log = console.getPropertyAsFunction(rt, "log");

        log.call(rt, jsi::String::createFromAscii(rt, "Called from the native module."));

        return jsi::Value::undefined();
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task13(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "getDateObject";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      0,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        auto date = std::make_shared<DateHostObject>();
        return jsi::Object::createFromHostObject(rt, date);
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task14(jsi::Runtime &rt) {
  static constexpr const char *propertyName = "getInfinityObject";

  jsi::Function fn = jsi::Function::createFromHostFunction(
      rt,
      jsi::PropNameID::forAscii(rt, propertyName),
      0,
      [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        auto infinity = std::make_shared<InfinityHostObject>();
        return jsi::Object::createFromHostObject(rt, infinity);
      });

  rt.global().setProperty(rt, propertyName, std::move(fn));
}

void NativeJSIWorkshopsModule::task15(jsi::Runtime &rt, jsi::Object simpleObject) {
  if (simpleObject.hasNativeState(rt)) {
    simpleObject.getNativeState<NativeStateCounter>(rt)->incrementCount();
  } else {
    simpleObject.setNativeState(rt, std::make_shared<NativeStateCounter>());
  }

  int count = simpleObject.getNativeState<NativeStateCounter>(rt)->getCount();
  auto console = rt.global().getPropertyAsObject(rt, "console");
  auto log = console.getPropertyAsFunction(rt, "log");
  log.call(rt, jsi::String::createFromAscii(rt, "[task15] counter: "), jsi::Value(count));
}

} // namespace facebook::react
