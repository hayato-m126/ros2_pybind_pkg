// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROS2_PYBIND_PKG__LISTENER_COMPONENT_HPP_
#define ROS2_PYBIND_PKG__LISTENER_COMPONENT_HPP_

#ifdef __cplusplus
extern "C" {
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_EXPORT __attribute__((dllexport))
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_IMPORT __attribute__((dllimport))
#else
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_EXPORT __declspec(dllexport)
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_IMPORT __declspec(dllimport)
#endif
#ifdef ROS2_PYBIND_PKG_LISTENER_COMPONENT_BUILDING_DLL
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_PUBLIC ROS2_PYBIND_PKG_LISTENER_COMPONENT_EXPORT
#else
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_PUBLIC ROS2_PYBIND_PKG_LISTENER_COMPONENT_IMPORT
#endif
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_PUBLIC_TYPE ROS2_PYBIND_PKG_LISTENER_COMPONENT_PUBLIC
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_LOCAL
#else
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_EXPORT __attribute__((visibility("default")))
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_IMPORT
#if __GNUC__ >= 4
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_PUBLIC __attribute__((visibility("default")))
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_LOCAL __attribute__((visibility("hidden")))
#else
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_PUBLIC
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_LOCAL
#endif
#define ROS2_PYBIND_PKG_LISTENER_COMPONENT_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // ROS2_PYBIND_PKG__LISTENER_COMPONENT_HPP_
