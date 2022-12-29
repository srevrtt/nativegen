#include <iostream>
#include <string>

#include "include/ProjectGenerator.hpp"
#include "include/Gen.hpp"

#include "../include/Utils.hpp"

ProjectInfo info;

// Analyzes and constructs project information for generation
void ProjectGenerator::analyze(std::vector<Token> tokens)
{
  bool analyzeProject = false;
  bool analyzeMetadata = false;

  int idx = 0;

  while (idx < tokens.size() - 1)
  {
    Token tok = tokens[idx];

    if (analyzeProject)
    {
      if (tok.name == "$T_LETTERS" && tokens[idx + 1].name == "$T_COLON")
      {
        idx += 2;

        if (tok.value == "version")
        {
          info.version = tokens[idx].value;
        }
        else if (tok.value == "author")
        {
          info.author = tokens[idx].value;
        }
        else if (tok.value == "name")
        {
          info.name = tokens[idx].value;
        }
        else if (tok.value == "identifier")
        {
          info.identifier = tokens[idx].value;
        }
        else if (tok.value == "description")
        {
          info.description = tokens[idx].value;
        }
        else
        {
          if (info.author != "" && info.version != "" && info.name != "" &&
            info.identifier != "" && info.description != "")
          {
            analyzeProject = false;
            idx -= 3;
          }
          else
          {
            Utilities::fatalError("Unknown token value \"" + tok.value + "\".");
          }
        }
      }
    }
    else if (analyzeMetadata)
    {
      if (tok.name == "$T_LETTERS" && tokens[idx + 1].name == "$T_COLON")
      {
        idx += 2;

        if (tok.value == "target_os")
        {
          info.targetOS = {"linux"}; // TODO: actually get the data here
        }
        else if (tok.value == "target_lang")
        {
          info.targetLang = tokens[idx].value;
        }
        else if (tok.value == "entrypoint")
        {
          info.entryPoint = tokens[idx].value;
        }
        else if (tok.value == "default_profile")
        {
          info.defaultProfile = tokens[idx].value;
        }
        else
        {
          if (info.targetOS[0] != "" && info.targetLang != "" && 
            info.entryPoint != "" && info.defaultProfile != "")
          {
            analyzeMetadata = false;
            continue;
          }

          Utilities::fatalError("Unknown token value \"" + tok.value + "\"."); 
        }
      }
    }
    else
    {
      if (tok.name == "$T_LETTERS" && tokens[idx + 1].name == "$T_COLON")
      {
        if (tok.value == "project")
        {
          analyzeProject = true;
        }

        if (tok.value == "metadata")
        {
          analyzeMetadata = true;
        }

        idx++;
        continue;
      }
    }

    idx++;
  }
}

// Generates a new project
void ProjectGenerator::gen(std::string filepath)
{
  #ifdef __linux__
    Generator::genLinuxProject(filepath, info);
  #endif
}
