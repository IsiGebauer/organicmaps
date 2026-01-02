//
// Created by emanuel on 12/30/25.
//

#include "trackGradeClassifier.hpp"
bool trackGradeClassifier::isGood(std::string_view arg_Value)
{
  return base::ListContains(goodTrackType, arg_Value, true, delims);
}
bool trackGradeClassifier::isBad(std::string_view arg_Value)
{
  return base::ListContains(badTrackType, arg_Value, true, delims);
}
bool trackGradeClassifier::isVeryBad(std::string_view arg_Value)
{
  return base::ListContains(veryBadTrackType, arg_Value, true, delims);
}
bool trackGradeClassifier::isPaved(std::string_view arg_Value)
{
  return arg_Value == pavedTrackType;
}

