#include <iostream>
#include <string>

#include "include/Analyzer.hpp"

#include "../include/Utils.hpp"
#include "../include/LexerUtils.hpp"

// Analyzes the stream of tokens and checks for errors
Analyzer::Analyzer(std::vector<LexerUtils::Token> tokens)
{
  this->tokens = tokens;
  idx = 0;

  while (idx < tokens.size() - 1)
  {
    if (tokens[idx].name == "$T_COLON")
    {
      // A label
      if (idx == 0 || tokens[idx - 1].name != "$T_LETTERS")
      {
        Utilities::fatalError("Unexpected ':'");
      }

      // FIXME: hardcoded values here
      if (tokens[idx - 1].value != "project" && tokens[idx - 1].value != "metadata")
      {
        if (tokens[idx + 1].name != "$T_STRING" && tokens[idx + 1].name != "$T_LEFT_BRACKET")
        {
          Utilities::fatalError("Expected string or array next to attribute.");
        }

        if (tokens[idx - 1].name != "$T_LETTERS")
        {
          Utilities::fatalError("Unexpected string or array for attribute name.");
        }
      }
    }

    if (tokens[idx].name == "$T_LEFT_BRACKET")
    {
      if (tokens[idx + 1].name != "$T_STRING")
      {
        Utilities::fatalError("Only strings are allowed inside arrays currently.");
      }

      while (tokens[idx].name != "$T_RIGHT_BRACKET")
      {
        if (tokens[idx].name == "$T_STRING" && tokens[idx].name != "$T_COMMA")
        {
          Utilities::fatalError("Expected comma after array value.");
        }

        idx += 2;
      }
    }

    if (tokens[idx].name == "$T_STRING" && tokens[idx + 1].name == "$T_STRING")
    {
      Utilities::fatalError("Unexpected string type after a string.");
    }

    if (tokens[idx].name == "$T_LETTERS" && tokens[idx + 1].name == "$T_LETTERS")
    {
      Utilities::fatalError("Unexpected group of letters after an existing group of letters.");
    }

    idx++;
  }  
}
