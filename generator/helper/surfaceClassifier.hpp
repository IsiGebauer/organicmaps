//
// Created by emanuel on 12/29/25.
//

#ifndef OMIM_SURFACECLASSIFIER_HPP
#define OMIM_SURFACECLASSIFIER_HPP
#include "base/stl_helpers.hpp"
#include "base/string_utils.hpp"
#include "string_view"
class surfaceClassifier
{
public:
  static bool isPaved(std::string_view arg_value);
  static bool isBad(std::string_view arg_value);
  static bool isVeryBad(std::string_view arg_value);
private:
  // According to https://wiki.openstreetmap.org/wiki/Key:surface
  static constexpr base::StringIL pavedSurfaces = {
      "asphalt", "cobblestone", "chipseal", "concrete", "grass_paver", "stone",
      "metal", "paved", "paving_stones", "sett", "brick", "bricks", "unhewn_cobblestone", "wood"
  };

    // All not explicitly listed surface types are considered unpaved good, e.g. "compacted", "fine_gravel".
    static constexpr base::StringIL badSurfaces = {
      "cobblestone", "dirt", "earth", "soil", "grass", "gravel", "ground", "metal", "mud", "rock", "stone", "unpaved",
      "pebblestone", "sand", "sett", "brick", "bricks", "snow", "stepping_stones", "unhewn_cobblestone",
      "grass_paver", "wood", "woodchips"
  };

    static constexpr base::StringIL veryBadSurfaces = {
      "dirt", "earth", "soil", "grass", "ground", "mud", "rock", "sand", "snow",
      "stepping_stones", "woodchips"
  };

  static inline const char * delims = ";:/";
};

#endif  // OMIM_SURFACECLASSIFIER_HPP
