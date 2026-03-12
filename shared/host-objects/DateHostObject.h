#pragma once

#include <jsi/jsi.h>

#include <ctime>
#include <string>
#include <vector>

namespace facebook::react {

/**
 * HostObject representing a date with year, month, and day fields.
 *
 * NOTE: Fields are validated individually. No cross-field validation is
 * performed, so the resulting date may be invalid (e.g. day=31, month=2).
 */
class DateHostObject : public jsi::HostObject {
 public:
  explicit DateHostObject();
  ~DateHostObject() override;

  jsi::Value get(jsi::Runtime &rt, const jsi::PropNameID &name) override;
  void set(jsi::Runtime &rt, const jsi::PropNameID &name, const jsi::Value &value) override;
  std::vector<jsi::PropNameID> getPropertyNames(jsi::Runtime &rt) override;

 private:
  int year_;
  int month_;
  int day_;

  std::string getNow() const;
};

} // namespace facebook::react
