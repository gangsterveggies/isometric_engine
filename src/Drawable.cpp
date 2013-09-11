#include "Drawable.hpp"

using namespace isometric_engine;

Drawable::Drawable ()
{
}

Drawable::Drawable (SDL_Surface *img, int _width, int _height)
{
  surface = img;
  width = _width;
  height = _height;
}
