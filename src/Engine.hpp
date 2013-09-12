#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <stdio.h>

#include "sdl_wrapper/Wrapper.hpp"
#include "Camera.hpp"
#include "Drawable.hpp"
#include <math.h>
#include <vector>
#include <queue>

#define ISO_CONST 0.5773502691896257

using namespace std;
using namespace sdl_wrapper;

namespace isometric_engine
{
  class Engine
  {
    public:
      Engine (SDL_Surface *screen, int _tile_size, int _horiz_number, int _vert_number, int _width, int _height);

      void insert_tile (SDL_Surface *tile);
      void draw ();
      void draw (Drawable *object);
      void set_tile (int x, int y, int type);
      void set_height (int x, int y, int val);
      int get_height (int x, int y);
      int get_tile (int x, int y);
      int get_iso_x (float x, float y);
      int get_iso_y (float x, float y);
      Camera *camera;

    private:
      int tile_size;
      int horiz_number;
      int vert_number;

      int screen_width;
      int screen_height;

      double width;
      double height;

      priority_queue <Drawable *, vector<Drawable *>, Drawable::cmp_drawable> render_queue;

      int** tile_matrix;
      int** height_matrix;

      vector <SDL_Surface *> tile_list;

      void init_tiles ();
  };
}

#endif
