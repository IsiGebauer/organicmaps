//
// Created by emanuel on 12/29/25.
//

#ifndef OMIM_TAGPROCESSOR_H
#define OMIM_TAGPROCESSOR_H

#include <string>
#include <generator/osm_element.hpp>
#include <functional>

class TagProcessor
{
public:
  explicit TagProcessor(OsmElement * elem) : m_element(elem) {}

  template <typename Function>
  struct Rule
  {
    char const * m_key;
    // Wildcard values:
    // * - take any values
    // ! - take only negative values
    // !r  - take only negative values for Routing
    // ~ - take only positive values
    // ~r - take only positive values for Routing
    // Note that the matching logic here is different from the one used in classificator matching,
    // see ParseMapCSS() and Matches() in generator/utils.cpp.
    char const * m_value;
    std::function<Function> m_func;
  };

  template <typename Function = void()>
  void ApplyRules(std::initializer_list<Rule<Function>> const & rules) const
  {
    for (auto & e : m_element->m_tags)
    {
      for (auto const & rule : rules)
      {
        if (e.m_key != rule.m_key)
          continue;

        bool take = false;
        if (rule.m_value[0] == '*')
          take = true;
        else if (strncmp(rule.m_value, "!r", 2) == 0)
          take = IsNegativeRouting(e.m_value);
        else if (strncmp(rule.m_value, "~r", 2) == 0)
          take = IsPositiveRouting(e.m_value);
        else if (rule.m_value[0] == '!')
          take = IsNegative(e.m_value);
        else if (rule.m_value[0] == '~')
          take = !IsNegative(e.m_value);

        if (take || e.m_value == rule.m_value)
          Call(rule.m_func, e.m_key, e.m_value);
      }
    }
  }

protected:
  static void Call(std::function<void()> const & f, std::string &, std::string &) ;
  static void Call(std::function<void(std::string &, std::string &)> const & f, std::string & k, std::string & v);

private:
  static bool IsNegative(std::string const & value);
  static bool IsNegativeRouting(std::string const & value);
  static bool IsPositiveRouting(std::string const & value);

  OsmElement * m_element;
};

#endif  // OMIM_TAGPROCESSOR_H
