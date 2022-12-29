#include <iostream>
#include <string>
#include <fstream>

#include "include/Utils.hpp"

// Reads a file
std::string Utilities::readSrc(std::string filename)
{
  std::ifstream file(filename);
  std::string line, content;

  if (file.is_open())
  {
    while (std::getline(file, line))
    {
      content += line + '\n';
    }
  }
  else
  {
    fatalError("Filename \"" + filename + "\" does not exist.");
  }

  return content;
}

// Writes a file to the hard drive
void Utilities::writeFile(std::string filename, std::string fileContents)
{
  std::ofstream file(filename);
  
  if (!file.is_open())
  {
    fatalError("Filepath does not exist: " + filename);
  }
  
  file << fileContents;
}

// Errors the program and quits
void Utilities::fatalError(std::string msg)
{
  std::cout << "Fatal Error: " << msg << std::endl;
  exit(1);
}
