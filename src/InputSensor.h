#ifndef INPUT_SENSOR_H
#define INPUT_SENSOR_H

#include "world.h"

class InputSensor
{
public:
  InputSensor(Node &node);

  virtual double sense(Creature *creature, World *world) = 0;

protected:
  Node &node;
};

class VisionSensor : public InputSensor
{
public:
  VisionSensor(Node &node, float view_distance, float view_angle);

  double sense(Creature *creature, World *world);

private:
  float view_distance;
  float view_angle;
};

#endif
