cmake_minimum_required(VERSION 3.22)
project(Jank_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(Jank_engine main.cpp Object.cpp Object.h PhysicsVector.cpp PhysicsVector.h TheFirstMover.cpp TheFirstMover.h Angle.cpp Angle.h)
