#pragma once

#include <string>
#include <vector>

namespace LexerUtils
{
  struct Token
  {
    std::string name;
    std::string value;
  };

  void skipWhitespace(int &idx, std::string src);
  void tokenizeArray(int &idx, std::string src, std::vector<Token> &tokens);

  std::string tokenizeString(int &idx, std::string src);
  std::string tokenizeLetters(int &idx, std::string src);
}
