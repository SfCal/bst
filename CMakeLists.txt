cmake_minimum_required(VERSION 3.16)
project(bstproject)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bstproject
        BST.cpp
        BST.hpp
        bstmain.cpp
        Phrase.cpp
        Phrase.hpp
        TNode.cpp
        TNode.hpp)
