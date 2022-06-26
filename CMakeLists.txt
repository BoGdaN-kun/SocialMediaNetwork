cmake_minimum_required(VERSION 3.21)
project(PROIECT_MARE)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROIECT_MARE main.cpp DataStructures/Node.h DataStructures/List.h DataStructures/Multimap.cpp DataStructures/Multimap.h Domain/User.cpp Domain/User.h Domain/Messages.cpp Domain/Messages.h Domain/Friend.cpp Domain/Friend.h Repository/Repository.cpp Repository/Repository.h Tests/TESTS.cpp Tests/TESTS.h Service/Service.cpp Service/Service.h UserInterface/UI.cpp UserInterface/UI.h Tests/PRESAVES.cpp Tests/PRESAVES.h Exceptions/MyExceptions.h)
