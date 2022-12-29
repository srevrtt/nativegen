#include <iostream>
#include <string>
#include <filesystem>

#include "include/Gen.hpp"
#include "../include/Utils.hpp"

// Generates a Linux-style project with the filename and the project information
void Generator::genLinuxProject(std::string filename, ProjectInfo info)
{
  if (info.targetLang == "\"c++\"")
  {
    printf ("\033[32;1mGenerating \"SimpleWindow\" project... \033[0m\n");
    // TODO: error handling

    printf ("Creating directories...\n");
    // Create directories
    std::filesystem::create_directory(filename + "/src");
    std::filesystem::create_directory(filename + "/src/include");
    std::filesystem::create_directory(filename + "/src/components");
    std::filesystem::create_directory(filename + "/src/components/include");
    std::filesystem::create_directory(filename + "/build");

    printf ("Copying build script...\n");
    // Copy Makefile
    std::filesystem::copy_file("../genfiles/linux/Window.mk", filename + "/Makefile");

    printf ("Copying `src/Main.cpp`...\n");
    printf ("Copying `src/App.cpp`...\n");
    printf ("Copying `src/components/Window.cpp`...\n");

    printf ("\033[32;1mFinished! \033[0m\n");
  }
}
