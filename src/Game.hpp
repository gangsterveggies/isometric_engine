#ifndef GAME_HPP
#define GAME_HPP

#include <SDL/SDL.h>

#include <string.h>
#include "Wrapper.hpp"
#include "MapParser.hpp"
#include "Drawable.hpp"
#include "Engine.hpp"

using namespace std;

class Game
{
  private:
    bool running;

    SDL_Event event;

    SDL_Surface *screen;
    Drawable *obj;

    Engine *engine;

  public:
    void setup();
    void run();
};

#endif
