//
// Created by emanuel on 12/29/25.
//

#include "surfaceClassifier.hpp"
#include "base/stl_helpers.hpp"

bool surfaceClassifier::isPaved(std::string_view arg_value)
{
  return base::ListContains(pavedSurfaces, arg_value, true, delims);
}
bool surfaceClassifier::isBad(std::string_view arg_value)
{
  return base::ListContains(badSurfaces, arg_value, true, delims);
}
bool surfaceClassifier::isVeryBad(std::string_view arg_value)
{
  return base::ListContains(veryBadSurfaces, arg_value, true, delims);
}
