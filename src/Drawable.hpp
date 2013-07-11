#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "Wrapper.hpp"

class Drawable
{
  public:
    Drawable (SDL_Surface *img, int _width, int _height);

    struct cmp_drawable
    {
      bool operator()(const Drawable* a, const Drawable* b) const
      {
        if (a->y != b->y)
          return b->y < a->y;
        else
          return b->x < a->x;
      }
    } typedef cmp_drawable;

    SDL_Surface *surface;

    int x;
    int y;
    int width;
    int height;

    bool operator < (Drawable *b);
};

#endif
