cmake_minimum_required(VERSION 3.0)
project(NativeGen VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(NGEN_SRCS src/ngen/Lexer.cpp src/ngen/Analyzer.cpp src/ngen/ProjectGenerator.cpp src/ngen/Gen.cpp)
set(SRCS ${NGEN_SRCS} src/Utils.cpp src/LexerUtils.cpp src/Main.cpp)

add_executable(NativeGen ${SRCS})
