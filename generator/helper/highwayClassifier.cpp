//
// Created by emanuel on 12/30/25.
//

#include "highwayClassifier.hpp"


bool highwayClassifier::isGoodPavedRoad(std::string_view arg_value)
{
  return base::ListContains(goodPavedRoads, arg_value, true, delims);
}
bool highwayClassifier::isIntermediatePavedRoads(std::string_view arg_value)
{
  return base::ListContains(intermediatePavedRoads, arg_value, true, delims);
}
bool highwayClassifier::isBadRoad(std::string_view arg_value)
{
  return base::ListContains(badRoads, arg_value, true, delims);
}