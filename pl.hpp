/*
 * Copyright (c) 2026- James-beans
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL version 2 was not distributed
 * with this file, You can obtain one at https://mozilla.org/MPL/2.0/ .
 */

#if !((defined(_MSVC_LANG) ? _MSVC_LANG : __cplusplus) >= 202302L)
  #error "pl.hpp requires at least C++23."
#endif

#ifndef PL_HPP
  #define PL_HPP

  #include <initializer_list>
  #include <vector>

template <typename T>
struct __pl_list {
  std::vector<T> entries;
  __pl_list(std::initializer_list<T> init) : entries(init) {}
  const std::vector<T>& get_entries() const { return entries; }
};

  #define pl(type, ...) __pl_list<type>({__VA_ARGS__})
  #define PL pl

#endif // PL_HPP