/*
  Starts the game loop and loads the state machine
 */

#include "Game.hpp"
#include <stdlib.h>
#include <vector>

using namespace std;

void Game::setup()
{
  running = true;

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_WM_SetCaption("isoengineDemo", NULL);
  screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

/*  SDL_RWops *tile_test_rwops = SDL_RWFromFile("res/grasstile4.png", "rb");
    SDL_Surface *tile_test = IMG_LoadPNG_RW(tile_test_rwops);*/
  SDL_RWops *obj_test_rwops = SDL_RWFromFile("res/tank.png", "rb");
  SDL_Surface *obj_test = IMG_LoadPNG_RW(obj_test_rwops);
  SDL_RWops *obj_test_rwops2 = SDL_RWFromFile("res/grasstile2.png", "rb");
  SDL_Surface *obj_test2 = IMG_LoadPNG_RW(obj_test_rwops2);
  obj = new Drawable (obj_test, 60, 40);
  obj->x = 4;
  obj->y = 3;

  vector<SDL_Surface*> obj2_list;
  obj2_list.push_back(obj_test);
  obj2_list.push_back(obj_test2);
  obj2 = new Animable (obj2_list, 60, 40);
  obj2->x = 2.2;
  obj2->y = 2.2;

  FILE* mfile = fopen ("res/testmap.isomap","r");
  MapParser::load_file(mfile);
  MapParser::parse_file();
  fclose(mfile);

  engine = new Engine (64, MapParser::get_horiz(), MapParser::get_vert(), 800, 600);

  while (MapParser::has_next())
  {
    engine->insert_tile(MapParser::next());
  }

  int i, j;
  for(i = 0; i < MapParser::get_vert(); i++)
  {
    for(j = 0; j < MapParser::get_horiz(); j++)
    {
      engine->set_tile(j, i, MapParser::get_tile(j, i));
      engine->set_height(j, i, MapParser::get_height(j, i));
    }
  }

/*  engine->insert_tile(tile_test);
  tile_test_rwops = SDL_RWFromFile("res/grasstile3.png", "rb");
  tile_test = IMG_LoadPNG_RW(tile_test_rwops);
  engine->insert_tile(tile_test);*/
}

void Game::run()
{
  int fr = 0;
  while (running)
  {
    SDL_WaitEvent(&event);
    switch (event.type) {
      case SDL_KEYDOWN:
        if (strcmp(SDL_GetKeyName(event.key.keysym.sym), "up") == 0)
            obj->y--;
//          engine->camera->set_y (engine->camera->get_raw_y() - 10);
        else if (strcmp(SDL_GetKeyName(event.key.keysym.sym), "right") == 0)
            obj->x++;
//          engine->camera->set_x (engine->camera->get_raw_x() + 10);
        else if (strcmp(SDL_GetKeyName(event.key.keysym.sym), "down") == 0)
            obj->y++;
//          engine->camera->set_y (engine->camera->get_raw_y() + 10);
        else if (strcmp(SDL_GetKeyName(event.key.keysym.sym), "left") == 0)
            obj->x--;
//          engine->camera->set_x (engine->camera->get_raw_x() - 10);
        else if (strcmp(SDL_GetKeyName(event.key.keysym.sym), "escape") == 0)
          running = false;
        else if (strcmp(SDL_GetKeyName(event.key.keysym.sym), "return") == 0)
          obj2->set_frame(1 - fr), fr = 1 - fr;
        break;
      case SDL_QUIT:
        running = false;
        break;
    }

    if (event.type == SDL_QUIT)
    {
      running = false;
    }

    engine->draw(screen, obj2);  
    engine->draw(screen, obj);
  
    engine->draw(screen);

    SDL_Flip(screen);
  }
}

int main(int argc, char *argv[])
{
  Game game;
  game.setup();
  game.run();

  return 0;
}
