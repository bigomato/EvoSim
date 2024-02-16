#ifndef CREATURE_H
#define CREATURE_H

#include "utils/vec2.h"
#include <SDL2/SDL.h>
#include <map>

using std::map;

class Creature {
public:
  Creature(float age, float max_speed, float size, float full_health,
           float current_health, float max_damage, float reproductice_drive,
           float reproductivity, float distance_travelled);
  ~Creature();

  void move(vec2<float> delta);
  void attemptEat();
  void attemptReproduce(Creature mate);
  void attemptFight(Creature enemy);
  void die();
  map<int, float> sense();

  void update(double dT);
  void draw(SDL_Renderer *renderer);

private:
  float age, max_speed, size, full_health, current_health, max_damage,
      reproductice_drive, reproductivity, distance_travelled;
  bool alive;
  vec2<float> birth_position;
  vec2<float> position;
  // Brain brain
  // DNA dna
};

#endif