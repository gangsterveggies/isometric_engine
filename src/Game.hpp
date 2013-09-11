#ifndef GAME_HPP
#define GAME_HPP

#include <SDL/SDL.h>

#include <string.h>

#include "sdl_wrapper/Wrapper.hpp"
#include "MapParser.hpp"
#include "Drawable.hpp"
#include "Animable.hpp"
#include "Engine.hpp"

using namespace std;
using namespace sdl_wrapper;
using namespace isometric_engine;

class Game
{
  private:
    bool running;

    SDL_Event event;

    SDL_Surface *screen;
    Drawable *obj;
    Animable *obj2;

    Engine *engine;

  public:
    void setup();
    void run();
};

#endif
