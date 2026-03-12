## Setup

```
npm i
cd ios && bundle install && bundle exec pod install
cd ..
npm start
npm run ios
npm run android
```

---

# JSI Cheatsheet (`facebook::jsi`)

## jsi::Value

### Constructors
```cpp
Value()                                    // undefined
Value(std::nullptr_t)                      // null
Value(bool b)
Value(double d)
Value(int i)
Value(Symbol&&)  / Value(BigInt&&)  / Value(String&&)  / Value(Object&&)  // move
Value(Runtime& rt, const Symbol&)          // copy
Value(Runtime& rt, const BigInt&)          // copy
Value(Runtime& rt, const String&)          // copy
Value(Runtime& rt, const Object&)          // copy
Value(Runtime& rt, const Value&)           // copy
```

### Static
```cpp
Value::undefined()
Value::null()
Value::createFromJsonUtf8(rt, json, length)
Value::strictEquals(rt, a, b)
```

### Type checks
```cpp
val.isUndefined()  val.isNull()  val.isBool()
val.isNumber()     val.isString() val.isBigInt()
val.isSymbol()     val.isObject()
```

### Reading values
> `get*` — asserts correct type, `as*` — throws exception on wrong type

```cpp
val.getBool()
val.getNumber()
val.getSymbol(rt)     val.getBigInt(rt)
val.getString(rt)     val.getObject(rt)

val.asBool()          val.asNumber()
val.asSymbol(rt)      val.asBigInt(rt)
val.asString(rt)      val.asObject(rt)

val.toString(rt)      // converts to String
```

---

## jsi::Object

### Constructors / factory
```cpp
Object(rt)                                                  // empty object
Object::createFromHostObject(rt, shared_ptr<HostObject>)
Object::create(rt, prototype_value)
```

### Properties
```cpp
obj.hasProperty(rt, "name")
obj.getProperty(rt, "name")       // → Value
obj.setProperty(rt, "name", val)  // T can be Value, bool, double, int, String, Object...

obj.getPropertyNames(rt)              // → Array
obj.getPropertyAsObject(rt, "name")   // → Object
obj.getPropertyAsFunction(rt, "name") // → Function
```

### Prototype
```cpp
obj.setPrototype(rt, prototype_value)
obj.getPrototype(rt)   // → Value
```

### Type checks / conversion
```cpp
obj.isArray(rt)          obj.getArray(rt)     obj.asArray(rt)
obj.isArrayBuffer(rt)    obj.getArrayBuffer(rt)
obj.isFunction(rt)       obj.getFunction(rt)  obj.asFunction(rt)
obj.isHostObject(rt)     obj.getHostObject<T>(rt)
obj.instanceOf(rt, ctor)
```

### Native State (C++ data attached to a JS object)
```cpp
obj.hasNativeState<T>(rt)
obj.getNativeState<T>(rt)   // → shared_ptr<T>
obj.setNativeState(rt, shared_ptr<NativeState>)
```

---

## jsi::Function

### Factory
```cpp
Function::createFromHostFunction(rt, PropNameID, paramCount, HostFunctionType)
```

### Calling
```cpp
fn.call(rt, arg1, arg2, ...)
fn.call(rt, args_ptr, count)
fn.call(rt, {val1, val2})           // initializer_list

fn.callWithThis(rt, thisObj, arg1, ...)
fn.callAsConstructor(rt, arg1, ...)

fn.isHostFunction(rt)
fn.getHostFunction(rt)              // → HostFunctionType&
```

### HostFunctionType
```cpp
using HostFunctionType = std::function<
    Value(Runtime& rt, const Value& thisVal, const Value* args, size_t count)>;
```

---

## jsi::Array

### Constructor / factory
```cpp
Array(rt, length)
Array::createWithElements(rt, val1, val2, ...)
Array::createWithElements(rt, {val1, val2})
```

### Access
```cpp
arr.size(rt)   /   arr.length(rt)
arr.getValueAtIndex(rt, i)       // → Value
arr.setValueAtIndex(rt, i, val)
```

---

## jsi::String

### Factory
```cpp
String::createFromAscii(rt, "hello")
String::createFromAscii(rt, str, length)
String::createFromUtf8(rt, utf8_str)
String::createFromUtf8(rt, utf8_ptr, length)
String::strictEquals(rt, a, b)
```

### Conversion
```cpp
str.utf8(rt)    // → std::string
str.utf16(rt)   // → std::u16string
```

---

## jsi::PropNameID

### Factory
```cpp
PropNameID::forAscii(rt, "name")
PropNameID::forAscii(rt, str, length)
PropNameID::forUtf8(rt, utf8_str)
PropNameID::forString(rt, jsi_string)
PropNameID::forSymbol(rt, jsi_symbol)
PropNameID::names(rt, "a", "b", "c")   // → vector<PropNameID>
```

### Comparison / conversion
```cpp
PropNameID::compare(rt, a, b)
pid.utf8(rt)    // → std::string
```

---

## jsi::BigInt

### Factory
```cpp
BigInt::fromInt64(rt, int64_value)
BigInt::fromUint64(rt, uint64_value)
BigInt::strictEquals(rt, a, b)
```

### Reading
```cpp
bi.isInt64(rt)   bi.getInt64(rt)   bi.asInt64(rt)   // throws on precision loss
bi.isUint64(rt)  bi.getUint64(rt)  bi.asUint64(rt)
bi.toString(rt, radix=10)
```

---

## jsi::Symbol

```cpp
sym.toString(rt)            // → std::string
Symbol::strictEquals(rt, a, b)
```

---

## jsi::WeakObject

```cpp
WeakObject(rt, obj)
weak.lock(rt)   // → Value (undefined if GC'd)
```

---

## jsi::ArrayBuffer

```cpp
ArrayBuffer(rt, shared_ptr<MutableBuffer>)
buf.size(rt)   /   buf.length(rt)
buf.data(rt)   // → uint8_t*
```

---

## jsi::HostObject

```cpp
class MyHostObject : public jsi::HostObject {
  Value get(Runtime& rt, const PropNameID& name) override;
  void set(Runtime& rt, const PropNameID& name, const Value& value) override;
  std::vector<PropNameID> getPropertyNames(Runtime& rt) override;
};

auto obj = Object::createFromHostObject(rt, std::make_shared<MyHostObject>());
```

---

## jsi::Runtime — key methods

```cpp
rt.global()                  // → Object (JS global object)
rt.description()             // → std::string
rt.evaluateJavaScript(buffer, sourceURL)
rt.queueMicrotask(fn)
rt.drainMicrotasks(maxHint)
```

---

## jsi::Scope

```cpp
{
  jsi::Scope scope(rt);      // push scope
  // local values released on block exit
}
Scope::callInNewScope(rt, [&]{ ... });
```

---

## jsi::JSError / exceptions

```cpp
// throwing
throw jsi::JSError(rt, "message");
throw jsi::JSINativeException("native error");

// catching
try { ... }
catch (const jsi::JSError& e) {
  e.getMessage()   // → std::string
  e.getStack()     // → std::string
  e.value()        // → const jsi::Value&
}
catch (const jsi::JSINativeException& e) {
  e.what()
}
```

---

## Common patterns

### Set a global variable
```cpp
rt.global().setProperty(rt, "myVar", jsi::Value(42));
```

### Create a JS function from C++
```cpp
auto fn = jsi::Function::createFromHostFunction(
  rt,
  jsi::PropNameID::forAscii(rt, "myFunc"),
  1, // paramCount
  [](jsi::Runtime& rt, const jsi::Value& thisVal,
     const jsi::Value* args, size_t count) -> jsi::Value {
    return jsi::Value(args[0].getNumber() * 2);
  }
);
rt.global().setProperty(rt, "myFunc", std::move(fn));
```

### Read a string from JS
```cpp
std::string s = args[0].asString(rt).utf8(rt);
```

### Return an object to JS
```cpp
jsi::Object result(rt);
result.setProperty(rt, "x", jsi::Value(1.0));
result.setProperty(rt, "y", jsi::Value(2.0));
return result;
```

### Call a JS function from C++
```cpp
auto fn = rt.global().getPropertyAsFunction(rt, "myJsFunc");
auto result = fn.call(rt, jsi::Value(42));
```
