//
// Created by emanuel on 12/30/25.
//

#ifndef OMIM_TRACKGRADECLASSIFIER_HPP
#define OMIM_TRACKGRADECLASSIFIER_HPP
#include <string_view>

#include "base/stl_helpers.hpp"
class trackGradeClassifier
{
public:
  static bool isGood(std::string_view arg_Value);
  static bool isBad(std::string_view arg_Value);
  static bool isVeryBad(std::string_view arg_Value);
  static bool isPaved(std::string_view arg_Value);
private:
  static constexpr char const * pavedTrackType = "grade1";
  static constexpr base::StringIL goodTrackType ={pavedTrackType, "grade2"};
  static constexpr base::StringIL badTrackType ={"grade3"};
  static constexpr base::StringIL veryBadTrackType ={"grade4", "grade5"};
  static const inline char * delims = ";:/";
};

#endif  // OMIM_TRACKGRADECLASSIFIER_HPP
