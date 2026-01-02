//
// Created by emanuel on 12/30/25.
//

#ifndef OMIM_HIGHWAYCLASSIFIER_HPP
#define OMIM_HIGHWAYCLASSIFIER_HPP
#include "base/stl_helpers.hpp"
class highwayClassifier
{
public:
  static bool isGoodPavedRoad(std::string_view arg_value);
  static bool isIntermediatePavedRoads(std::string_view arg_value);
  static bool isBadRoad(std::string_view arg_value);
  private:
  static constexpr base::StringIL goodPavedRoads = {"motorway", "trunk", "primary", "secondary"};
  static constexpr base::StringIL intermediatePavedRoads = {"tertiary", "residential"};
  static constexpr base::StringIL badRoads = {"track", "service", "path"};
  static const inline char * delims = ";:/";
};

#endif  // OMIM_HIGHWAYCLASSIFIER_HPP
