#pragma once
#include <string>

namespace Utilities
{
  std::string readSrc(std::string src);
  void writeFile(std::string filename, std::string fileContents);
  void fatalError(std::string msg);
}
