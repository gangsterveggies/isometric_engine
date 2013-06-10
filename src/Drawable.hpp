#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "Wrapper.hpp"

class Drawable
{
  public:
    Drawable (SDL_Surface *img, int _width, int _height);

    SDL_Surface *surface;

    int x;
    int y;
    int width;
    int height;

    bool operator < (Drawable *b);
};

#endif
