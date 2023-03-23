cmake_minimum_required(VERSION 3.21)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab7 main.cpp Domain/Cheltuiala.h Domain/Cheltuiala.cpp Repository/Repository.h Repository/Repository.cpp Domain/Vector.h UI/Console.cpp UI/Console.h Tests/TestEntityRepo.h Tests/TestEntityRepo.cpp Service/CheltuialaService.cpp Service/CheltuialaService.h Tests/TestsService.h Tests/TestsService.cpp Tests/TestAll.h Domain/Validator.h)
