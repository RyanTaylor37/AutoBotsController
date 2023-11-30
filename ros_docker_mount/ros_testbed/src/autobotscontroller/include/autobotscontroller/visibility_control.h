#ifndef AUTOBOTSCONTROLLER__VISIBILITY_CONTROL_H_
#define AUTOBOTSCONTROLLER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define AUTOBOTSCONTROLLER_EXPORT __attribute__ ((dllexport))
    #define AUTOBOTSCONTROLLER_IMPORT __attribute__ ((dllimport))
  #else
    #define AUTOBOTSCONTROLLER_EXPORT __declspec(dllexport)
    #define AUTOBOTSCONTROLLER_IMPORT __declspec(dllimport)
  #endif
  #ifdef AUTOBOTSCONTROLLER_BUILDING_LIBRARY
    #define AUTOBOTSCONTROLLER_PUBLIC AUTOBOTSCONTROLLER_EXPORT
  #else
    #define AUTOBOTSCONTROLLER_PUBLIC AUTOBOTSCONTROLLER_IMPORT
  #endif
  #define AUTOBOTSCONTROLLER_PUBLIC_TYPE AUTOBOTSCONTROLLER_PUBLIC
  #define AUTOBOTSCONTROLLER_LOCAL
#else
  #define AUTOBOTSCONTROLLER_EXPORT __attribute__ ((visibility("default")))
  #define AUTOBOTSCONTROLLER_IMPORT
  #if __GNUC__ >= 4
    #define AUTOBOTSCONTROLLER_PUBLIC __attribute__ ((visibility("default")))
    #define AUTOBOTSCONTROLLER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define AUTOBOTSCONTROLLER_PUBLIC
    #define AUTOBOTSCONTROLLER_LOCAL
  #endif
  #define AUTOBOTSCONTROLLER_PUBLIC_TYPE
#endif
#endif  // AUTOBOTSCONTROLLER__VISIBILITY_CONTROL_H_
// Generated 30-Nov-2023 09:53:22
// Copyright 2019-2020 The MathWorks, Inc.
