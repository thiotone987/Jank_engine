cmake_minimum_required(VERSION 3.13.1)

Message( STATUS "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR} )
Message( STATUS "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR} )
Message( STATUS "CMAKE_COMMAND: " ${CMAKE_COMMAND} )
Message( STATUS "CMAKE_VERSION: " ${CMAKE_VERSION} )
Message( STATUS "CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER} )
Message( STATUS "CMAKE_PROJECT_NAME: " ${CMAKE_PROJECT_NAME} )

project(Jank_engine)

# ------- Set Vars ------- #

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
set(SOURCE_FILES  main.cpp Object.cpp Object.h PhysicsVector.cpp Unit.cpp Unit.h PhysicsVector.h TheFirstMover.cpp TheFirstMover.h Graphics.cpp Graphics.h Input.cpp Input.h Game.cpp Game.h SchizoMap.cpp SchizoMap.h)

Message("")
Message( STATUS "SOURCE entry point : " ${SOURCE_FILES} )
Message("")

# ------- End Set Vars --- #

# ------- Executable ----- #

ADD_EXECUTABLE(Jank_engine ${SOURCE_FILES})

# ------- End Executable - #

# ------- Finds ---------- #

FIND_PACKAGE(SDL2 REQUIRED)
Message("")
Message( STATUS "FINDING SDL2" )
IF (${SDL2_FOUND})
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( STATUS "SDL2_INCLUDE_DIR:" ${SDL2_INCLUDE_DIR})
    Message( STATUS "SDL2_LIBRARY: " ${SDL2_LIBRARY})
ELSE()
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( FATAL_ERROR "SDL2 NOT FOUND" )
ENDIF()

FIND_PACKAGE(SDL2_IMAGE)
Message("")
Message( STATUS "FINDING SDL2_IMAGE" )
Message( STATUS "SDL2_IMAGE_FOUND: " ${SDL2_IMAGE_FOUND})
IF (${SDL2_IMAGE_FOUND})
    Message( STATUS "SDL2_IMAGE_INCLUDE_DIR: " ${SDL2_IMAGE_INCLUDE_DIR})
    Message( STATUS "SDL2_IMAGE_LIBRARY: " ${SDL2_IMAGE_LIBRARY})
ELSE()
    Message( FATAL_ERROR "SDL2_IMAGE NOT FOUND" )
ENDIF()

FIND_PACKAGE(SDL2TTF)
Message("")
Message( STATUS "FINDING SDL2TTF" )
Message( STATUS "SDL2TTF_FOUND: " ${SDL2TTF_FOUND} )
IF (${SDL2TTF_FOUND})
    Message( STATUS "SDL2TTF_INCLUDE_DIR: " ${SDL2TTF_INCLUDE_DIR})
    Message( STATUS "SDL2TTF_LIBRARY: " ${SDL2TTF_LIBRARY})
ELSE()
    Message( FATAL_ERROR "SDL2TTF NOT FOUND" )
ENDIF()
Message("")

FIND_PACKAGE(SDL2Mixer)

Message( STATUS "FINDING SDL2Mixer" )
Message( STATUS "SDL2Mixer_FOUND: " ${SDL2Mixer_FOUND} )

Message("")

# ------- End Finds ------ #

# ------- Inc & Link ---- #

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2Mixer_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2Mixer_LIBRARY} )

# ------- End ----------- #

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Boost REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

target_link_libraries(Jank_engine ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(Jank_engine ${CMAKE_CURRENT_BINARY_DIR}/freeglut.dll)
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(_WINDOWS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    add_compile_definitions(_DARWIN)
endif()

add_compile_definitions(GL_SILENCE_DEPRECATION)
add_compile_options(-Wall -Wextra -Wpedantic)
