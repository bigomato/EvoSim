#ifndef CREATURE_H
#define CREATURE_H

#include "brain.h"
#include "world.h"
#include "utils/vec2.h"
#include "input_sensor.h"
#include <SDL2/SDL.h>
#include <map>
#include <memory>
#include "action_emitter.h"

class ActionEmitter;
class InputSensor;
class World;

using std::map;

class Creature
{
public:
  Creature(float age, float max_speed, float size, float full_health,
           float current_health, float max_damage, float reproductice_drive,
           float reproductivity);
  ~Creature();

  float max_speed;

  void move(vec2<float> delta);
  void setPos(vec2<float> pos);
  void addInputSensorAndCreateNode(auto *input_sensor, double bias,
                                   int activationFunction);
  void addActionEmitterAndCreateNode(auto *action_emitter, double bias,
                                     int activationFunction);
  vec2<float> getPos();
  float getSpeed();
  void setSpeed(float speed);
  float getAngle();
  void setAngle(float angle);
  void attemptEat();
  void attemptReproduce(Creature mate);
  void attemptFight(Creature enemy);
  void die();
  void sense(World *world);
  Brain *getBrain() { return &brain; }
  void addNodeToBrain(Node *node);
  void addConnectionToBrain(Connection *connection);

  void update(double dT, World *world);
  void draw(SDL_Renderer *renderer);

private:
  float age, size, full_health, current_health, max_damage,
      reproductice_drive, reproductivity, distance_travelled, speed;
  bool alive;
  vec2<float> birth_position;
  float angle;
  vec2<float> position;
  Brain brain;
  vector<std::shared_ptr<InputSensor>> input_sensors;
  vector<std::shared_ptr<ActionEmitter>> action_emitters;
  // DNA dna
};

#endif