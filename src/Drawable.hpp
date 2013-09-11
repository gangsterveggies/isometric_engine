#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "sdl_wrapper/Wrapper.hpp"

using namespace sdl_wrapper;

namespace isometric_engine
{
  class Drawable
  {
    public:
      Drawable ();
      Drawable (SDL_Surface *img, int _width, int _height);

      struct cmp_drawable
      {
          bool operator()(const Drawable* a, const Drawable* b) const
          {
            if ((int)a->y != (int)b->y)
              return b->y < a->y;
            else
              return b->x < a->x;
          }
      } typedef cmp_drawable;

      SDL_Surface *surface;

      float x;
      float y;
      int width;
      int height;

      bool operator < (Drawable *b);
  };
}

#endif
