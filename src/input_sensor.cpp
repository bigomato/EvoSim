#include "input_sensor.h"

#include "creature.h"
#include "world.h"
#include <cmath>

InputSensor::InputSensor(int node_id) : node_id(node_id) {}

VisionSensor::VisionSensor(int node_id, float view_distance, float view_angle)
    : InputSensor(node_id) {
  this->view_distance = view_distance;
  this->view_angle = view_angle;
}

double VisionSensor::sense(Creature *creature, World *world) {
  // TODO: Implement VisionSensor::sense
  return INFINITY;
}
