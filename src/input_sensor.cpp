#include "input_sensor.h"

#include "creature.h"
#include "world.h"
#include <cmath>

InputSensor::InputSensor()
{
  this->node = nullptr;
}

VisionSensor::VisionSensor(float view_distance, float view_angle)
    : InputSensor()
{
  this->view_distance = view_distance;
  this->view_angle = view_angle;
}

double VisionSensor::sense(Creature *creature, World *world)
{
  // Implement a detection algorithm using ray casting
  // to detect creatures within the view distance and angle
  // Direction of the creature + sensor angle/2 (right) and -sensor angle/2 (left)

  // Get the direction of the creature
  float creatureDirection = creature->getAngle();

  // Calculate the start and end angles for ray casting
  float startAngle = creatureDirection - (view_angle / 2);
  float endAngle = creatureDirection + (view_angle / 2);

  // Iterate through all creatures in the world
  for (auto otherCreature : world->getCreatures())
  {
    // Skip the current creature
    if (&otherCreature == creature)
      continue;

    // Get the position of the other creature
    float otherCreatureX = otherCreature.getPos().x;
    float otherCreatureY = otherCreature.getPos().x;

    // Calculate the distance between the creatures
    float distance = std::sqrt(std::pow(otherCreatureX - creature->getPos().x, 2) + std::pow(otherCreatureY - creature->getPos().y, 2));

    // Check if the other creature is within the view distance and angle
    if (distance <= view_distance && std::abs(creatureDirection - std::atan2(otherCreatureY - creature->getPos().y, otherCreatureX - creature->getPos().y)) <= view_angle / 2)
    {
      node->value = distance;
    }
  }

  // Return the sensed value
  return 0.0; // Replace with the actual sensed value
}
