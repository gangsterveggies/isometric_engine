project (isoengine)
cmake_minimum_required (VERSION 2.8)

find_package (SDL REQUIRED)
find_package (SDL_image REQUIRED)

link_libraries (
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  SDLmain
)

add_library (Wrapper.o src/Wrapper.cpp)
add_library (Camera.o src/Camera.cpp)
add_library (Drawable.o src/Drawable.cpp)
add_library (MapParser.o src/MapParser.cpp)
add_library (Engine.o src/Engine.cpp)

link_libraries (Engine.o)

add_executable (isoengine src/Game.cpp)
target_link_libraries (isoengine Wrapper.o)
target_link_libraries (isoengine Camera.o)
target_link_libraries (isoengine Drawable.o)
target_link_libraries (isoengine MapParser.o)
target_link_libraries (isoengine Engine.o)
