#pragma once

#include "Lexer.hpp"
#include "../../include/LexerUtils.hpp"

class Analyzer
{
private:
  std::vector<LexerUtils::Token> tokens;
  int idx;
public:
  Analyzer(std::vector<LexerUtils::Token> tokens);
};
