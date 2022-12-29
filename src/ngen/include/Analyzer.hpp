#pragma once
#include "Lexer.hpp"

class Analyzer
{
private:
  std::vector<Token> tokens;
  int idx;
public:
  Analyzer(std::vector<Token> tokens);
};
