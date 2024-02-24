#ifndef INPUT_SENSOR_H
#define INPUT_SENSOR_H

#include "world.h"
#include "creature.h"

class Creature;
class World;

class InputSensor
{
public:
  InputSensor();

  virtual double sense(Creature *creature, World *world) = 0;
  void setNode(Node *node) { this->node = node; }
  void setId(int id) { this->id = id; }

protected:
  Node *node;
  int id;
};

class VisionSensor : public InputSensor
{
public:
  VisionSensor(float view_distance, float view_angle);

  double sense(Creature *creature, World *world);

private:
  float view_distance;
  float view_angle;
};

#endif
