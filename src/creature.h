#ifndef CREATURE_H
#define CREATURE_H

#include "brain.h"
#include "utils/vec2.h"
#include "input_sensor.h"
#include <SDL2/SDL.h>
#include <map>

using std::map;

class Creature
{
public:
  Creature(float age, float max_speed, float size, float full_health,
           float current_health, float max_damage, float reproductice_drive,
           float reproductivity, float distance_travelled, float angle);
  ~Creature();

  float max_speed;

  void move(vec2<float> delta);
  void setPos(vec2<float> pos);
  void addInputSensor(InputSensor input_sensor);
  vec2<float> getPos();
  float getSpeed();
  void setSpeed(float speed);
  float getAngle();
  void setAngle(float angle);
  void attemptEat();
  void attemptReproduce(Creature mate);
  void attemptFight(Creature enemy);
  void die();
  map<int, float> sense();

  void update(double dT);
  void draw(SDL_Renderer *renderer);

private:
  float age, size, full_health, current_health, max_damage,
      reproductice_drive, reproductivity, distance_travelled, speed;
  bool alive;
  vec2<float> birth_position;
  float angle;
  vec2<float> position;
  Brain brain;
  vector<InputSensor> input_sensors;
  // DNA dna
};

#endif