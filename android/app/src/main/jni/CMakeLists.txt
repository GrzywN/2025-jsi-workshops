cmake_minimum_required(VERSION 3.13)

# Define the library name here.
project(appmodules)

# This file includes all the necessary to let you build your React Native application
include(${REACT_ANDROID_DIR}/cmake-utils/ReactNative-application.cmake)

# Define where the additional source code lives. We need to crawl back the jni, main, src, app, android folders
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
  ../../../../../shared/NativeJSIWorkshopsModule.cpp
  ../../../../../shared/host-objects/DateHostObject.cpp
  ../../../../../shared/host-objects/InfinityHostObject.cpp
  ../../../../../shared/native-states/NativeStateCounter.cpp
)

# Define where CMake can find the additional header files. We need to crawl back the jni, main, src, app, android folders
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ../../../../../shared ../../../../../shared/host-objects ../../../../../shared/native-states)
