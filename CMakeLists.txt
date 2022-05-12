cmake_minimum_required(VERSION 3.22)
project(Jank_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(Jank_engine main.cpp Direction.cpp Direction.h Object.cpp Object.h TheFirstMover.cpp TheFirstMover.h Angle.cpp Angle.h)
