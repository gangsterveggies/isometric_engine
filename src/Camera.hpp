#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera
{
  public:
    Camera (int _width, int _height);
    int get_x ();
    int get_raw_x ();
    void set_x (int _x);
    int get_y ();
    int get_raw_y ();
    void set_y (int _y);

  private:
    int screen_width;
    int screen_height;
    int x;
    int y;
    double zoom;

};

#endif
