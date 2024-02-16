#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>

class World {
public:
  World();
  ~World();

  int startSimulation();

private:
  int width, height;
  int w_width, w_height;
  long double time;

  SDL_Window *window;
  SDL_Renderer *renderer;

  void update(double dt);
  void draw();
  int init();
  void loop();
  void handleEvents(SDL_Event &e, bool &running);
  void kill();
};
#endif