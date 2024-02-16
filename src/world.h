#ifndef WORLD_H
#define WORLD_H

#include "creature.h"
#include <SDL2/SDL.h>
#include <vector>

using std::vector;

class World {
public:
  World();
  ~World();

  int startSimulation();

private:
  int width, height;
  int w_width, w_height;
  long double time;
  vector<Creature> creatures;

  SDL_Window *window;
  SDL_Renderer *renderer;

  void update(double dt);
  void draw();
  int init();
  void loop();
  void handleEvents(SDL_Event &e, bool &running);
  void kill();
  void spawnCreatures(int n, float max_speed, float size, float full_health,
                      float max_damage, float reproductivity);
};
#endif