#ifndef ANIMABLE_HPP
#define ANIMABLE_HPP

#include "sdl_wrapper/Wrapper.hpp"
#include "Drawable.hpp"
#include <vector>

using namespace std;
using namespace sdl_wrapper;

namespace isometric_engine
{
  class Animable: public Drawable
  {
    public:
      Animable (vector<SDL_Surface*> _img_list, int _width, int _height);
      void set_frame (int num);

      vector<SDL_Surface*> img_list;
  };
}

#endif
