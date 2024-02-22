#ifndef INPUT_SENSOR_H
#define INPUT_SENSOR_H

#include "world.h"

class InputSensor {
public:
  InputSensor(int node_id);

  virtual double sense(Creature *creature, World *world) = 0;

protected:
  int node_id;
};

class VisionSensor : public InputSensor {
public:
  VisionSensor(int node_id, float view_distance, float view_angle);

  double sense(Creature *creature, World *world);

private:
  float view_distance;
  float view_angle;
};

#endif
