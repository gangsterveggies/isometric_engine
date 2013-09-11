#include "MapParser.hpp"

using namespace isometric_engine;

vector <SDL_Surface *> MapParser::tile_list;
FILE* MapParser::map_file;

int** MapParser::tile_matrix;
int** MapParser::height_matrix;

int MapParser::horiz_number;
int MapParser::vert_number;

void MapParser::load_file (FILE* _map_file)
{
  map_file = _map_file;
}

void MapParser::parse_file ()
{
  int tile_number;
  fscanf(map_file, "%d", &tile_number);

  int i, j;
  for (i = 0; i < tile_number; i++)
  {
    char line[500];
    fscanf(map_file, " %s", line);
    tile_list.push_back(Wrapper::load_image(line));
  }
  reverse(tile_list.begin(), tile_list.end());

  fscanf(map_file, "%d %d", &horiz_number, &vert_number);

  tile_matrix = (int **) malloc (vert_number * sizeof(int *));
  height_matrix = (int **) malloc (vert_number * sizeof(int *));

  for (i = 0; i < vert_number; i++)
  {
    tile_matrix[i] = (int *) malloc(horiz_number * sizeof(int));
    height_matrix[i] = (int *) malloc(horiz_number * sizeof(int));
  }

  for(i = 0; i < vert_number; i++)
  {
    for(j = 0; j < horiz_number; j++)
    {
      fscanf(map_file, "%d", &tile_matrix[i][j]);
    }
  }

  for(i = 0; i < vert_number; i++)
  {
    for(j = 0; j < horiz_number; j++)
    {
      fscanf(map_file, "%d", &height_matrix[i][j]);
    }
  }
}

int MapParser::get_horiz ()
{
  return horiz_number;
}


int MapParser::get_vert ()
{
  return vert_number;
}

int MapParser::get_tile (int x, int y)
{
  return tile_matrix[y][x];
}
int MapParser::get_height (int x, int y)
{
  return height_matrix[y][x];
}

SDL_Surface* MapParser::next ()
{
  SDL_Surface* nx = tile_list.back();
  tile_list.pop_back();
  return nx;
}

bool MapParser::has_next ()
{
  return !tile_list.empty();
}
