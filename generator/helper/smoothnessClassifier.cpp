//
// Created by emanuel on 12/29/25.
//

#include "smoothnessClassifier.hpp"
#include "base/stl_helpers.hpp"

bool smoothnessClassifier::hasMidSmoothness(std::string_view arg_Value)
{
  return base::ListContains(midSmoothness, arg_Value, true, delims);
}

bool smoothnessClassifier::hasVeryBadSmoothness(std::string_view arg_Value)
{
  return base::ListContains(veryBadSmoothness, arg_Value, true, delims);
}

bool smoothnessClassifier::hasGoodPathSmoothness(std::string_view arg_Value)
{
  return base::ListContains(goodPathSmoothness, arg_Value, true, delims);
}

bool smoothnessClassifier::hasBadSmoothness(std::string_view arg_Value)
{
  return base::ListContains(badPathSmoothness, arg_Value, true, delims);
}