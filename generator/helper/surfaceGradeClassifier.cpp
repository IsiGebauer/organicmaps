//
// Created by emanuel on 1/2/26.
//

#include "surfaceGradeClassifier.hpp"

bool surfaceGradeClassifier::hasVeryBadSurfaceGrade(int arg_value)
{
  return arg_value == veryBad;
}
bool surfaceGradeClassifier::hasBadSurfaceGrade(int arg_value)
{
  return arg_value == bad;
}
bool surfaceGradeClassifier::hasDescentSurfaceGrade(int arg_value)
{
  return arg_value == descent;
}
bool surfaceGradeClassifier::hasExcellentSurfaceGrade(int arg_value)
{
  return arg_value == excellent;
}