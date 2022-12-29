#pragma once
#include "Lexer.hpp"

struct ProjectInfo
{
  std::string name;
  std::string identifier;
  std::string targetLang;
  std::string version;
  std::string author;
  std::string description;
  std::vector<std::string> targetOS;
  std::string entryPoint;
  std::string defaultProfile;
};

namespace ProjectGenerator
{
  void analyze(std::vector<Token> tokens);
  void gen(std::string filepath);
}
