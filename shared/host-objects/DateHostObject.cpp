#include "DateHostObject.h"

namespace facebook::react {

static constexpr int YEAR_OFFSET = 1900;

DateHostObject::DateHostObject() {
  time_t rawtime;
  time(&rawtime);
  struct tm *timeinfo = localtime(&rawtime);
  year_ = timeinfo->tm_year + YEAR_OFFSET;
  month_ = timeinfo->tm_mon;
  day_ = timeinfo->tm_mday;
}

DateHostObject::~DateHostObject() {}

std::string DateHostObject::getNow() const {
  time_t now = time(0);
  return ctime(&now);
}

jsi::Value DateHostObject::get(jsi::Runtime &rt, const jsi::PropNameID &name) {
  std::string prop = name.utf8(rt);

  if (prop == "now") {
    return jsi::String::createFromUtf8(rt, getNow());
  }

  if (prop == "day") {
    return jsi::Value(day_);
  }

  if (prop == "month") {
    return jsi::Value(month_);
  }

  if (prop == "year") {
    return jsi::Value(year_);
  }

  return jsi::Value::undefined();
}

void DateHostObject::set(jsi::Runtime &rt, const jsi::PropNameID &name, const jsi::Value &value) {
  std::string prop = name.utf8(rt);

  if (prop == "day") {
    int day = (int)value.asNumber();

    if (day != value.asNumber()) {
      throw jsi::JSError(rt, "[DateHostObject] Day must be an integer");
    }

    if (day < 1) {
      throw jsi::JSError(rt, "[DateHostObject] Day must be greater than 0");
    }

    if (day > 31) {
      throw jsi::JSError(rt, "[DateHostObject] Day must be less than or equal to 31");
    }

    day_ = day;
  }

  if (prop == "month") {
    int month = (int)value.asNumber();

    if (month != value.asNumber()) {
      throw jsi::JSError(rt, "[DateHostObject] Month must be an integer");
    }

    if (month < 1) {
      throw jsi::JSError(rt, "[DateHostObject] Month must be greater than 0");
    }

    if (month > 12) {
      throw jsi::JSError(rt, "[DateHostObject] Month must be less than or equal to 12");
    }

    month_ = month;
  }

  if (prop == "year") {
    int year = (int)value.asNumber();

    if (year != value.asNumber()) {
      throw jsi::JSError(rt, "[DateHostObject] Year must be an integer");
    }

    if (year < 1) {
      throw jsi::JSError(rt, "[DateHostObject] Year must be greater than 0");
    }

    year_ = year;
  }
}

std::vector<jsi::PropNameID> DateHostObject::getPropertyNames(jsi::Runtime &rt) {
  std::vector<jsi::PropNameID> properties;
  properties.push_back(jsi::PropNameID::forAscii(rt, "now"));
  properties.push_back(jsi::PropNameID::forAscii(rt, "day"));
  properties.push_back(jsi::PropNameID::forAscii(rt, "month"));
  properties.push_back(jsi::PropNameID::forAscii(rt, "year"));

  return properties;
}

} // namespace facebook::react
