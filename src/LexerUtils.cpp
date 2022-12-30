#include <iostream>
#include <string>

#include "include/LexerUtils.hpp"
#include "include/Utils.hpp"

// Skips any unneeded whitespace
void LexerUtils::skipWhitespace(int &idx, std::string src)
{
  while (isspace(src[idx]))
  {
    idx++;
  }
}

// Tokenizes a string
std::string LexerUtils::tokenizeString(int &idx, std::string src)
{
  std::string str = "\"";

  while (src[idx] != '"')
  {
    str += src[idx];
    idx++;
  }

  if (src[idx] != '"')
  {
    Utilities::fatalError("Missing ending '\"' after string.");
  }

  str += '"';

  idx++;
  skipWhitespace(idx, src);

  return str;
}

// Tokenizes a group of letters
std::string LexerUtils::tokenizeLetters(int &idx, std::string src)
{
  std::string letters;

  while (isalpha(src[idx]) || src[idx] == '_')
  {
    letters += src[idx];
    idx++;
  }

  return letters;
}

// Tokenizes an array
void LexerUtils::tokenizeArray(int &idx, std::string src, std::vector<Token> &tkns)
{
  skipWhitespace(idx, src);

  while (src[idx] != ']')
  {
    if (src[idx] == '"')
    {
      idx++;

      tkns.push_back(Token {"$T_STRING", tokenizeString(idx, src)});
      skipWhitespace(idx, src);
    }

    if (src[idx] == ']')
    {
      idx++;
      break;
    }

    if (src[idx] != ',')
    {
      Utilities::fatalError("Expected ',' after item in array.");
    }

    tkns.push_back(Token {"$T_COMMA", ","});
    skipWhitespace(idx, src);

    idx++;
    skipWhitespace(idx, src);
  }
}
