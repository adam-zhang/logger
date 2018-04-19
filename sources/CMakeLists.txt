cmake_minimum_required(VERSION 2.8)
project(logger)
set(CMAKE_BUILD_TYPE "Debug")
set(sources main.cpp
	Logger.cpp)
set(headers Logger.h
	Singleton.h)
add_executable(${PROJECT_NAME} ${sources} ${headers})
