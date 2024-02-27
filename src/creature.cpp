#include "node.h"
#include "creature.h"
#include "world.h"
#include "input_sensor.h"
#include "action_emitter.h"
#include "utils/vec2.h"

class Node;
class ActionEmitter;

Creature::Creature(float age, float max_speed, float size, float full_health,
                   float current_health, float max_damage,
                   float reproductice_drive, float reproductivity)
{
  this->age = age;
  this->max_speed = max_speed;
  this->size = size;
  this->full_health = full_health;
  this->current_health = current_health;
  this->max_damage = max_damage;
  this->reproductice_drive = reproductice_drive;
  this->reproductivity = reproductivity;
  this->distance_travelled = 0;
  this->alive = true;
  this->birth_position = vec2<float>(0, 0);
  this->position = vec2<float>(0, 0);
  this->angle = angle;

  double (*activationFunction)(double) = [](double x)
  { return x; };
  VisionSensor *sensor = new VisionSensor(0, 90);

  this->addInputSensorAndCreateNode(sensor, 0.0, activationFunction);
  MoveSpeedEmitter *emitter = new MoveSpeedEmitter(1);
  this->addActionEmitterAndCreateNode(emitter, 0, activationFunction);

  Connection *conn = new Connection(0, 1, 0);
  this->brain.addConnection(conn);
}

Creature::~Creature() {}

void Creature::move(vec2<float> delta)
{
  this->position += delta;
  this->distance_travelled += delta.length();
}

void Creature::setPos(vec2<float> pos)
{
  this->position = pos;
  this->birth_position = pos;
}

vec2<float> Creature::getPos() { return this->position; }

void Creature::setAngle(float angle) { this->angle = angle; }

float Creature::getAngle() { return this->angle; }

void Creature::die() { this->alive = false; }

void Creature::update(double dT, World *world)
{
  if (this->current_health <= 0)
  {
    this->die();
  }
  this->sense(world);
  this->brain.feedForward();
  // Apply the output of the brain to the creature
  for (std::shared_ptr<ActionEmitter> &sensor : this->action_emitters)
  {
    sensor->emit(this);
  }
  this->move(vec2<float>(cos(getAngle()), sin(getAngle())) * this->speed * dT);
  this->age += dT;
}

void Creature::draw(SDL_Renderer *renderer)
{
  SDL_Rect rect;
  rect.x = this->position.x - this->size / 2;
  rect.y = this->position.y - this->size / 2;
  rect.w = this->size;
  rect.h = this->size;
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect);

  vec2<float> end = vec2<float>(cos(getAngle()), sin(getAngle())) * 50 + this->position;

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

  SDL_RenderDrawLine(renderer, this->position.x, this->position.y, end.x, end.y);
}

void Creature::addInputSensorAndCreateNode(auto *sensor, double bias,
                                           double (*activationFunction)(double x))
{
  Node *node = new Node(0, bias);
  sensor->setNode(node);
  this->brain.addNode(node);
  this->input_sensors.push_back(std::shared_ptr<InputSensor>(sensor));
  this->input_sensors.back()->setId(this->input_sensors.size() - 1);
}

void Creature::addNodeToBrain(Node *node) { this->brain.addNode(node); }

void Creature::addActionEmitterAndCreateNode(auto *action_emitter, double bias,
                                             double (*activationFunction)(double x))
{
  Node *node = new Node(2, bias);
  action_emitter->setNode(node);
  this->brain.addNode(node);
  this->action_emitters.push_back(std::shared_ptr<ActionEmitter>(action_emitter));
  this->action_emitters.back()->setId(this->action_emitters.size() - 1);
}

void Creature::sense(World *world)
{
  for (std::shared_ptr<InputSensor> &sensor : this->input_sensors)
  {
    sensor->sense(this, world);
  }
}

void Creature::setSpeed(float speed) { this->speed = speed; }