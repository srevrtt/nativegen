#pragma once

#include <vector>
#include <string>
#include "../../include/LexerUtils.hpp"

class Lexer
{
private:
  std::vector<LexerUtils::Token> tkns;
  std::string src;
  int idx;
public:
  Lexer(std::string src);
  std::vector<LexerUtils::Token> getTokens();
};
