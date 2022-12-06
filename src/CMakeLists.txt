cmake_minimum_required(VERSION 3.23)
project(s3910902)

set(CMAKE_CXX_STANDARD 14)

add_executable(s3910902 main.cpp ../include/milestone4.h Node.cpp ../include/Node.h NodeList.cpp ../include/NodeList.h PathSolver.cpp ../include/PathSolver.h ../include/Types.h)
