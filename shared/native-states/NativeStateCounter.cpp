#include "NativeStateCounter.h"

namespace facebook::react {

NativeStateCounter::NativeStateCounter() : count_(0) {}

NativeStateCounter::~NativeStateCounter() {}

void NativeStateCounter::incrementCount() {
  count_++;
}

int NativeStateCounter::getCount() const {
  return count_;
}

} // namespace facebook::react
