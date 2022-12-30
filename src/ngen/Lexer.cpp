#include <iostream>
#include <string>

#include "../include/Utils.hpp"
#include "../include/LexerUtils.hpp"

#include "include/Lexer.hpp"

// FIXME: string after string causes infinite loop
// TODO: unexpected token error

// Creates a new lexer
Lexer::Lexer(std::string src)
{
  idx = 0;
  this->src = src;

  while (idx < src.length() - 1)
  {
    LexerUtils::skipWhitespace(idx, src);
    std::string letters = LexerUtils::tokenizeLetters(idx, src);
    LexerUtils::skipWhitespace(idx, src);

    if (src[idx] == ':')
    {
      tkns.push_back(LexerUtils::Token {"$T_LETTERS", letters});
      tkns.push_back(LexerUtils::Token {"$T_COLON", ":"});

      LexerUtils::skipWhitespace(idx, src);
      idx++;
      LexerUtils::skipWhitespace(idx, src);

      if (src[idx] == '"' || src[idx] == '[')
      {
        if (src[idx] == '"')
        {
          idx++;
          tkns.push_back(LexerUtils::Token {"$T_STRING", LexerUtils::tokenizeString(idx, src)});
        }
        else if (src[idx] == '[')
        {
          idx++;
          LexerUtils::skipWhitespace(idx, src);

          tkns.push_back(LexerUtils::Token {"$T_LEFT_BRACKET", "["});

          LexerUtils::tokenizeArray(idx, src, tkns);
          tkns.push_back(LexerUtils::Token {"$T_RIGHT_BRACKET", "]"});
        }
      }
    }

    LexerUtils::skipWhitespace(idx, src);
  }
}

// Gets all of the tokens generated by the lexer
std::vector<LexerUtils::Token> Lexer::getTokens()
{
  return tkns;
}
