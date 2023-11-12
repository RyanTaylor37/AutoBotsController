#ifndef CARSIMPLESIMULINK__VISIBILITY_CONTROL_H_
#define CARSIMPLESIMULINK__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CARSIMPLESIMULINK_EXPORT __attribute__ ((dllexport))
    #define CARSIMPLESIMULINK_IMPORT __attribute__ ((dllimport))
  #else
    #define CARSIMPLESIMULINK_EXPORT __declspec(dllexport)
    #define CARSIMPLESIMULINK_IMPORT __declspec(dllimport)
  #endif
  #ifdef CARSIMPLESIMULINK_BUILDING_LIBRARY
    #define CARSIMPLESIMULINK_PUBLIC CARSIMPLESIMULINK_EXPORT
  #else
    #define CARSIMPLESIMULINK_PUBLIC CARSIMPLESIMULINK_IMPORT
  #endif
  #define CARSIMPLESIMULINK_PUBLIC_TYPE CARSIMPLESIMULINK_PUBLIC
  #define CARSIMPLESIMULINK_LOCAL
#else
  #define CARSIMPLESIMULINK_EXPORT __attribute__ ((visibility("default")))
  #define CARSIMPLESIMULINK_IMPORT
  #if __GNUC__ >= 4
    #define CARSIMPLESIMULINK_PUBLIC __attribute__ ((visibility("default")))
    #define CARSIMPLESIMULINK_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CARSIMPLESIMULINK_PUBLIC
    #define CARSIMPLESIMULINK_LOCAL
  #endif
  #define CARSIMPLESIMULINK_PUBLIC_TYPE
#endif
#endif  // CARSIMPLESIMULINK__VISIBILITY_CONTROL_H_
// Generated 06-Nov-2023 22:39:22
// Copyright 2019-2020 The MathWorks, Inc.
