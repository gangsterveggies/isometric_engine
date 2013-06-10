#include "Drawable.hpp"

Drawable::Drawable (SDL_Surface *img, int _width, int _height)
{
  surface = img;
  width = _width;
  height = _height;
}

bool Drawable::operator < (Drawable *b)
{
  return b->y < y;
}
