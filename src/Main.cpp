#include <iostream>
#include <string>

#include "ngen/include/Lexer.hpp"
#include "ngen/include/Analyzer.hpp"
#include "ngen/include/ProjectGenerator.hpp"

#include "include/Utils.hpp"

int main(int argc, char *argv[])
{
  std::string fileContents = Utilities::readSrc("../examples/SimpleWindow/SimpleWindow.ngen");
  Lexer *lexer = new Lexer(fileContents);
  std::vector<Token> tokens = lexer->getTokens();
  Analyzer *analyzer = new Analyzer(tokens);

  ProjectGenerator::analyze(tokens);
  ProjectGenerator::gen("../examples/SimpleWindow/SimpleWindow");

  delete lexer;
  delete analyzer;

  return 0;
}
