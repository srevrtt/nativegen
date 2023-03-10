// Generated by NativeGen v0.1.0

#include <iostream>
#include <string>

#ifdef __linux__
  #include "linux/include/NGLinuxWindow.hpp"
#endif

#include "include/NGWindow.hpp"

// Creates a new NativeGen window
NGWindow::NGWindow()
{
  #ifdef __linux__
    window = new NGLinuxWindow();
  #endif
}

// Runs the window
void NGWindow::run()
{
  #ifdef __linux__
    window->run();
  #endif
}
