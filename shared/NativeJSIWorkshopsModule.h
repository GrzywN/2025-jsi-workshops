#pragma once

#include <JSIWorkshopsJSI.h>

#include <memory>
#include <string>

namespace facebook::react {

class NativeJSIWorkshopsModule : public NativeJSIWorkshopsModuleCxxSpec<NativeJSIWorkshopsModule> {
 public:
  NativeJSIWorkshopsModule(std::shared_ptr<CallInvoker> jsInvoker);

  void install(jsi::Runtime &rt);
  void task1(jsi::Runtime &rt);
  void task2(jsi::Runtime &rt);
  void task3(jsi::Runtime &rt);
  void task4(jsi::Runtime &rt);
  void task5(jsi::Runtime &rt);
  void task6(jsi::Runtime &rt);
  void task7(jsi::Runtime &rt);
  void task8(jsi::Runtime &rt);
  void task9(jsi::Runtime &rt);
  void task10(jsi::Runtime &rt);
  void task11(jsi::Runtime &rt);
  void task12(jsi::Runtime &rt);
  void task13(jsi::Runtime &rt);
  void task14(jsi::Runtime &rt);
  void task15(jsi::Runtime &rt, jsi::Object simpleObject);
};

} // namespace facebook::react
