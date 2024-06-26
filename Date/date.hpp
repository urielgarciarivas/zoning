/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel García Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * https://github.com/zoningorg/zoning/blob/main/LICENSE
 */

#pragma once

#include <string>
#include <map>

namespace grz {

static const std::map<int, const std::string> months = {
  {1, "Jan"},
  {2, "Feb"},
  {3, "Mar"},
  {4, "Apr"},
  {5, "May"},
  {6, "Jun"},
  {7, "Jul"},
  {8, "Aug"},
  {9, "Sep"},
  {10, "Oct"},
  {11, "Nov"},
  {12, "Dec"}
};

class date final {
 public:
  // QUESTION: Should this constructor be explicit?
  /* explicit */ date() noexcept = default;
  explicit date(const date&) noexcept = default;

  /**
   * 1-based integers, as in any standard calendar.
   *
   * 'std::to_string' may throw.
   */
  date(int day, int month, int year)
      : day_(day),
        month_(month),
        year_(year),
        str_(std::to_string(day) + " " + months.at(month) + " " + std::to_string(year)) {}

  date day_from(int days) const noexcept { return {}; }

  int day() const noexcept { return day_; }
  int month() const noexcept { return month_; }
  int year() const noexcept { return year_; }
  const std::string& str() const noexcept { return str_; }

 private:
  int day_;
  int month_;
  int year_;
  const std::string str_;
};

} // namespace grz
