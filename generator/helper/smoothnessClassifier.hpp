//
// Created by emanuel on 12/29/25.
//

#ifndef OMIM_SMOOTHNESSCLASSIFIER_HPP
#define OMIM_SMOOTHNESSCLASSIFIER_HPP
#include <string_view>
#include "base/stl_helpers.hpp"
class smoothnessClassifier
{
public:
  static bool hasMidSmoothness(std::string_view arg_Value);

  static bool hasVeryBadSmoothness(std::string_view arg_Value);

  static bool hasGoodPathSmoothness(std::string_view arg_Value);

  static bool hasBadSmoothness(std::string_view arg_Value);
private:
  static inline base::StringIL badPathSmoothness = {"bad"};
  static inline base::StringIL veryBadSmoothness = {
    "very_bad",       "horrible",        "very_horrible", "impassable",
    "robust_wheels", "high_clearance", "off_road_wheels", "rough"
};

  static inline base::StringIL midSmoothness = {
    "unknown", "intermediate"
};

  static inline base::StringIL goodPathSmoothness = {
    "excellent", "good", "very_good", "intermediate"
};

  static inline const char * delims = ";:/";
};

#endif  // OMIM_SMOOTHNESSCLASSIFIER_HPP
