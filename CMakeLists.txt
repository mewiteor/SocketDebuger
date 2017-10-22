cmake_minimum_required(VERSION 3.8)
project(SocketDebuger
		VERSION 0.1.0.0
		LANGUAGES CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin/$<CONFIG>")

include(Checks.cmake)

add_subdirectory(Common)
add_subdirectory(Client)
add_subdirectory(Server)
add_subdirectory(UI)