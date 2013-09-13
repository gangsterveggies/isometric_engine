SET (PROJECT_NAME "isoengine")

project (isoengine)
cmake_minimum_required (VERSION 2.8)

find_package (SDL REQUIRED)
find_package (SDL_image REQUIRED)

link_libraries (
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  SDLmain
)

file (GLOB_RECURSE ISOENGINE_SOURCES "src/*.cpp")
file (GLOB_RECURSE ISOENGINE_INCLUDES "src/*.hpp")

list (REMOVE_ITEM ISOENGINE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/sdl_wrapper/Demo.cpp)
list (REMOVE_ITEM ISOENGINE_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/sdl_wrapper/Demo.cpp)

include_directories (ISOENGINE_INCLUDES)
add_executable (${PROJECT_NAME} ${ISOENGINE_SOURCES})
target_link_libraries (${PROJECT_NAME} ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})
