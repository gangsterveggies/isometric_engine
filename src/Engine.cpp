/*
  The Isometric Engine that renders the game
 */

#include "Engine.hpp"

using namespace isometric_engine;

Engine::Engine (SDL_Surface *screen, int _tile_size, int _horiz_number, int _vert_number, int _width, int _height)
{
  Wrapper::set_screen(screen);

  tile_size = _tile_size;
  horiz_number = _horiz_number;
  vert_number = _vert_number;

  width = tile_size;
  height = (int)(ISO_CONST * (double)tile_size);

  screen_width = _width;
  screen_height = _height;

  camera = new Camera (screen_width, screen_height);

  init_tiles();
}

void Engine::init_tiles ()
{
  tile_matrix = (int **) malloc (vert_number * sizeof(int *));
  height_matrix = (int **) malloc (vert_number * sizeof(int *));

  int i, j;
  for (i = 0; i < vert_number; i++)
  {
    tile_matrix[i] = (int *) malloc(horiz_number * sizeof(int));
    height_matrix[i] = (int *) malloc(horiz_number * sizeof(int));
  }

  for(i = 0; i < vert_number; i++)
  {
    for(j = 0; j < horiz_number; j++)
    {
      tile_matrix[i][j] = 1;
      height_matrix[i][j] = 0;
    }
  }
}

void Engine::set_tile (int x, int y, int type)
{
  if (type > tile_list.size() || type < 0)
  {
    return;
  }

  tile_matrix[y][x] = type;
}

void Engine::set_height (int x, int y, int val)
{
  height_matrix[y][x] = val;
}

int Engine::get_height (int x, int y)
{
  return height_matrix[y][x];
}

int Engine::get_tile (int x, int y)
{
  return tile_matrix[y][x];
}

void Engine::insert_tile (SDL_Surface *tile)
{
  tile_list.push_back(tile);
}

void Engine::draw ()
{
  Wrapper::clear_screen(0, 0, 0);

  if (tile_list.size() > 0)
  {
    int i, j, ct = 0;

    for(i = 0; i < vert_number; i++)
    {
      for(j = 0; j < horiz_number; j++)
      {
        if (tile_matrix[i][j])
          Wrapper::draw_image (tile_list[tile_matrix[i][j] - 1], (int)(camera->get_x() + (j - i) * width / 2), (int)(camera->get_y() + (i + j) * height / 2) - height_matrix[i][j], (int)width, (int)height);

        while (!render_queue.empty() && (int)render_queue.top()->y == i && (int)render_queue.top()->x == j)
        {
          Drawable *object = render_queue.top();
          Wrapper::draw_image(object->surface, (int)(camera->get_x() + (object->x - object->y) * width / 2), (int)(camera->get_y() - object->height + (object->y + object->x + 1) * height / 2 - height_matrix[(int)object->y][(int)object->x]), object->width, object->height);
          render_queue.pop();
        }
      }
    }

    while (!render_queue.empty())
    {
      render_queue.pop();
    }
  }  
}

void Engine::draw (Drawable *object)
{
  if (object->x < 0 || object->x >= horiz_number || object->y < 0 || object->y >= vert_number)
    return;
  render_queue.push (object);
}
