#include "Animable.hpp"

Animable::Animable (vector<SDL_Surface*> _img_list, int _width, int _height)
{
  img_list = _img_list;
  surface = img_list[0];
  width = _width;
  height = _height;
}

void Animable::set_frame (int num)
{
  if (num >= img_list.size() || num < 0)
    return;
  surface = img_list[num];
}
