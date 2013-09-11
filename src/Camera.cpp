#include "Camera.hpp"

using namespace isometric_engine;

Camera::Camera (int _width, int _height)
{
  screen_width = _width;
  screen_height = _height;
  x = 0;
  y = 0;
  zoom = 1;
}

int Camera::get_x ()
{
  return x + screen_width / 2;
}

int Camera::get_raw_x ()
{
  return x;
}

void Camera::set_x (int _x)
{
  x = _x;
}

int Camera::get_y ()
{
  return y + screen_height / 3;
}

int Camera::get_raw_y ()
{
  return y;
}

void Camera::set_y (int _y)
{
  y = _y;
}
