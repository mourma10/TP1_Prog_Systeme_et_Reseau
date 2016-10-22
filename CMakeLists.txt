cmake_minimum_required(VERSION 3.6)
project(TP1_Prog_Systeme_et_Reseau)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES exercice1.c myfunctions.h myfunctions.c exercice2.c)
add_executable(TP1_Prog_Systeme_et_Reseau ${SOURCE_FILES})