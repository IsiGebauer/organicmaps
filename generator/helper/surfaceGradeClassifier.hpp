//
// Created by emanuel on 1/2/26.
//

#ifndef OMIM_SURFACEGRADECLASSIFIER_HPP
#define OMIM_SURFACEGRADECLASSIFIER_HPP

class surfaceGradeClassifier
{
public:
  static bool hasVeryBadSurfaceGrade(int arg_value);
  static bool hasBadSurfaceGrade(int arg_value);
  static bool hasDescentSurfaceGrade(int arg_value);
  static bool hasExcellentSurfaceGrade(int arg_value);
private:
  enum surfaceGrade
  {
    // as defined in https://wiki.openstreetmap.org/wiki/Key:surface:grade
    veryBad = 0,
    bad = 1,
    descent = 2,
    excellent = 3
  };
};

#endif  // OMIM_SURFACEGRADECLASSIFIER_HPP
