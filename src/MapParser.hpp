#ifndef MAPARSER_HPP
#define MAPARSER_HPP

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <algorithm>

using namespace std;

#include "Wrapper.hpp"

class MapParser
{
  public:
    static void load_file (FILE* _map_file);
    static void parse_file ();

    static int get_horiz ();
    static int get_vert ();

    static int get_tile (int x, int y);
    static int get_height (int x, int y);

    static SDL_Surface* next ();
    static bool has_next ();
    
  private:
    static vector <SDL_Surface *> tile_list;
    static FILE* map_file;

    static int** tile_matrix;
    static int** height_matrix;

    static int horiz_number;
    static int vert_number;
};

#endif
