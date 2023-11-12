#ifndef SUBTRACTOR__VISIBILITY_CONTROL_H_
#define SUBTRACTOR__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SUBTRACTOR_EXPORT __attribute__ ((dllexport))
    #define SUBTRACTOR_IMPORT __attribute__ ((dllimport))
  #else
    #define SUBTRACTOR_EXPORT __declspec(dllexport)
    #define SUBTRACTOR_IMPORT __declspec(dllimport)
  #endif
  #ifdef SUBTRACTOR_BUILDING_LIBRARY
    #define SUBTRACTOR_PUBLIC SUBTRACTOR_EXPORT
  #else
    #define SUBTRACTOR_PUBLIC SUBTRACTOR_IMPORT
  #endif
  #define SUBTRACTOR_PUBLIC_TYPE SUBTRACTOR_PUBLIC
  #define SUBTRACTOR_LOCAL
#else
  #define SUBTRACTOR_EXPORT __attribute__ ((visibility("default")))
  #define SUBTRACTOR_IMPORT
  #if __GNUC__ >= 4
    #define SUBTRACTOR_PUBLIC __attribute__ ((visibility("default")))
    #define SUBTRACTOR_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SUBTRACTOR_PUBLIC
    #define SUBTRACTOR_LOCAL
  #endif
  #define SUBTRACTOR_PUBLIC_TYPE
#endif
#endif  // SUBTRACTOR__VISIBILITY_CONTROL_H_
// Generated 06-Nov-2023 21:59:06
// Copyright 2019-2020 The MathWorks, Inc.
