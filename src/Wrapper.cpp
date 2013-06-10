/*
  Includes, but is not limited to, several functions which
  serve as an interface to SDL's native drawing functions.
 */

#include "Wrapper.hpp"

void Wrapper::set_pixel(SDL_Surface *screen, int x, int y, Uint8 color)
{
  /* Draws a pixel on the screen at (x, y) with color 'color' */
  Uint8 *p;
  p = (Uint8 *) screen->pixels + y * screen->pitch + x * screen->format->BytesPerPixel;
  *p = color;
}


void Wrapper::clear_screen(SDL_Surface *screen, int r, int g, int b)
{
  /* Clears the screen by drawing a rectangle with color R,G,B on it */
  Uint8 background_color = SDL_MapRGB(screen->format, r, g, b);
  SDL_FillRect(screen, NULL, background_color);
}

SDL_Surface* Wrapper::load_image (char path[500])
{
  SDL_RWops *tile_test_rwops = SDL_RWFromFile(path, "rb");
  return IMG_LoadPNG_RW(tile_test_rwops);
}

void Wrapper::draw_image(SDL_Surface *screen, SDL_Surface *img, int x, int y, int width, int height)
{
  SDL_Rect tile = {x, y, width, height};
  SDL_BlitSurface(img, NULL, screen, &tile);
}

void Wrapper::draw_line(SDL_Surface *screen, int x1, int y1, int x2, int y2, Uint8 color)
{
  /* Draw a line from (x1, y1) to (x2, y2) */
  int dy = y2 - y1;
  int dx = x2 - x1;
  int stepx;
  int stepy;

  if (dy < 0)
  {
    dy = -dy;
    stepy = -1;
  }
  else
  {
    stepy = 1;
  }

  if (dx < 0)
  {
    dx = -dx;
    stepx = -1;
  }
  else
  {
    stepx = 1;
  }

  dy <<= 1;
  dx <<= 1;

  set_pixel(screen, x1, y1, color); /* Draw first pixel */

  if (dx > dy)
  {
    int fraction = dy - (dx >> 1);

    while (x1 != x2)
    {
      if (fraction >= 0)
      {
        y1 += stepy;
        fraction -= dx;
      }

      x1 += stepx;
      fraction += dy;
      set_pixel(screen, x1, y1, color);
    }
  }
  else
  {
    int fraction = dx - (dy >> 1);

    while (y1 != y2)
    {
      if (fraction >= 0)
      {
        x1 += stepx;
        fraction -= dy;
      }

      y1 += stepy;
      fraction += dx;
      set_pixel(screen, x1, y1, color);
    }
  }
}
