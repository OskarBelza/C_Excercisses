cmake_minimum_required(VERSION 3.27)
project(../C_Excercisses C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

enable_language(CXX)

add_executable(Zad_1_1 ../C_Excercisses/Zadania_1/Zad_1.c)
add_executable(Zad_1_2 ../C_Excercisses/Zadania_1/Zad_2.c)
add_executable(Zad_1_3 ../C_Excercisses/Zadania_1/Zad_3.c)
add_executable(Zad_1_4 ../C_Excercisses/Zadania_1/Zad_4.c)
add_executable(Zad_1_5 ../C_Excercisses/Zadania_1/Zad_5.c)
add_executable(Zad_1_6 ../C_Excercisses/Zadania_1/Zad_6.c)
add_executable(Zad_2_1 ../C_Excercisses/Zadania_2/Zad_1.c)
add_executable(Zad_2_2 ../C_Excercisses/Zadania_2/Zad_2.c)
add_executable(Zad_2_3 ../C_Excercisses/Zadania_2/Zad_3.c)
add_executable(Zad_2_4 ../C_Excercisses/Zadania_2/Zad_4.c)
add_executable(Zad_2_5 ../C_Excercisses/Zadania_2/Zad_5.c)
add_executable(Zad_3_1 ../C_Excercisses/Zadania_3/Zad_1.c)
add_executable(Zad_3_2 ../C_Excercisses/Zadania_3/Zad_2.c)
add_executable(Zad_4_1 ../C_Excercisses/Zadania_4/Zad_1.c)
add_executable(Zad_4_2 ../C_Excercisses/Zadania_4/Zad_2.c)
add_executable(Zad_4_3 ../C_Excercisses/Zadania_4/Zad_3.c)
add_executable(Zad_5_1 ../C_Excercisses/Zadania_5/Zad_1.c)
add_executable(Zad_5_2 ../C_Excercisses/Zadania_5/Zad_2.c)
add_executable(Zad_5_3 ../C_Excercisses/Zadania_5/Zad_3.c)
add_executable(Zad_5_4 ../C_Excercisses/Zadania_5/Zad_4.c)
add_executable(Zad_5_5 ../C_Excercisses/Zadania_5/Zad_5.c)
add_executable(Zad_5_6 ../C_Excercisses/Zadania_5/Zad_6.c)
add_executable(Zad_6_1 ../C_Excercisses/Zadania_6/Zad_1.c)
add_executable(Zad_6_2 ../C_Excercisses/Zadania_6/Zad_2.c)
add_executable(Zad_6_3 ../C_Excercisses/Zadania_6/Zad_3.c)
add_executable(Zad_7_1 ../C_Excercisses/Zadania_7/Zad_1.c)
add_executable(Zad_7_1_2 ../C_Excercisses/Zadania_7/Zad_1_2.c)
add_executable(Zad_7_2 ../C_Excercisses/Zadania_7/Zad_2.c)
add_executable(Zad_7_2_2 ../C_Excercisses/Zadania_7/Zad_2_2.c)

set_source_files_properties(
        ../C_Excercisses/C++/Zad_7_1.cpp
        ../C_Excercisses/C++/Zad_7_1_2.cpp
        ../C_Excercisses/C++/Zad_7_2.cpp
        ../C_Excercisses/C++/Zad_7_2_2.cpp
        PROPERTIES LANGUAGE CXX
)

add_executable(Zad_7_1_C_plus ../C_Excercisses/C++/Zad_7_1.cpp)
add_executable(Zad_7_1_2_C_plus ../C_Excercisses/C++/Zad_7_1_2.cpp)
add_executable(Zad_7_2_C_plus ../C_Excercisses/C++/Zad_7_2.cpp)
add_executable(Zad_7_2_2_C_plus ../C_Excercisses/C++/Zad_7_2_2.cpp)
