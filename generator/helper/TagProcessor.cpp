//
// Created by emanuel on 12/29/25.
//

#include "TagProcessor.hpp"

void TagProcessor::Call(std::function<void()> const & f, std::string &, std::string &) { f(); }

void TagProcessor::Call(std::function<void(std::string &, std::string &)> const & f, std::string & k, std::string & v)
{
  f(k, v);
  k.clear();
  v.clear();
}

bool TagProcessor::IsNegative(std::string const & value)
{
  for (char const * s : {"no", "none", "false"})
  {
    if (value == s)
      return true;
  }
  return false;
}
bool TagProcessor::IsNegativeRouting(std::string const & value)
{
  for (char const * s : {"use_sidepath", "separate"})
  {
    if (value == s)
      return true;
  }
  return IsNegative(value);
}
bool TagProcessor::IsPositiveRouting(std::string const & value)
{
  // This values neither positive and neither negative.
  for (char const * s : {"unknown", "dismount"})
  {
    if (value == s)
      return false;
  }
  return !IsNegativeRouting(value);
}