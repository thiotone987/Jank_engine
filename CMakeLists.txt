cmake_minimum_required(VERSION 3.22)
project(Jank_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(Jank_engine main.cpp Object.cpp Object.h PhysicsVector.cpp PhysicsVector.h TheFirstMover.cpp TheFirstMover.h)

#cmake_minimum_required(VERSION 3.6)
#project(Jank_engine)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

#include_directories(C:/Users/caryj/CLionProjects/Jank_engine/SDL2/include)
#link_directories(C:/Users/caryj/CLionProjects/Jank_engine/SDL2/lib)

#set(SOURCE_FILES main.cpp)
#add_executable(Jank_engine ${SOURCE_FILES})

#target_link_libraries(Jank_engine mingw32 SDL2main SDL2)
