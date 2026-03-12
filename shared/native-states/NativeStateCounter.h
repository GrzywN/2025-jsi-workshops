#pragma once

#include <jsi/jsi.h>

namespace facebook::react {

class NativeStateCounter : public jsi::NativeState {
 public:
  NativeStateCounter();
  ~NativeStateCounter() override;

  void incrementCount();
  int getCount() const;

 private:
  int count_;
};

} // namespace facebook::react
