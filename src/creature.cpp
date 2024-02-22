#include "creature.h"
#include "utils/vec2.h"

Creature::Creature(float age, float max_speed, float size, float full_health,
                   float current_health, float max_damage,
                   float reproductice_drive, float reproductivity,
                   float distance_travelled, float angle)
{
  this->age = age;
  this->max_speed = max_speed;
  this->size = size;
  this->full_health = full_health;
  this->current_health = current_health;
  this->max_damage = max_damage;
  this->reproductice_drive = reproductice_drive;
  this->reproductivity = reproductivity;
  this->distance_travelled = distance_travelled;
  this->alive = true;
  this->birth_position = vec2<float>(0, 0);
  this->position = vec2<float>(0, 0);
  this->angle = angle;
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

void Creature::update(double dT)
{
  if (this->current_health <= 0)
  {
    this->die();
  }
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
