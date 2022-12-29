#pragma once

#include <vector>
#include <string>

struct Token
{
  std::string name;
  std::string value;
};

class Lexer
{
private:
  std::vector<Token> tkns;
  std::string src;
  int idx;

  void skipWhitespace();
  void tokenizeArray();

  std::string tokenizeString();
  std::string tokenizeLetters();
public:
  Lexer(std::string src);
  std::vector<Token> getTokens();
};
