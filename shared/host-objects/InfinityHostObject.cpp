#include "InfinityHostObject.h"

namespace facebook::react {

InfinityHostObject::InfinityHostObject() {
  counter_ = 0;
}

InfinityHostObject::~InfinityHostObject() {}

jsi::Value InfinityHostObject::get(jsi::Runtime &rt, const jsi::PropNameID &name) {
  counter_++;

  return jsi::Value(counter_);
}

void InfinityHostObject::set(jsi::Runtime &rt, const jsi::PropNameID &name, const jsi::Value &value) {
  counter_--;
}

std::vector<jsi::PropNameID> InfinityHostObject::getPropertyNames(jsi::Runtime &rt) {
  std::vector<jsi::PropNameID> properties;

  return properties;
}

} // namespace facebook::react
