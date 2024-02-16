#include "creature.h"

Creature::Creature(float age, float max_speed, float size, float full_health,
                   float current_health, float max_damage,
                   float reproductice_drive, float reproductivity,
                   float distance_travelled) {
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
}

Creature::~Creature() {}

void Creature::move(vec2<float> delta) {
  this->position += delta;
  this->distance_travelled += delta.length();
}

void Creature::setPos(vec2<float> pos) {
  this->position = pos;
  this->birth_position = pos;
}

void Creature::die() { this->alive = false; }

void Creature::update(double dT) {
  if (this->current_health <= 0) {
    this->die();
  }
  this->age += dT;
}

void Creature::draw(SDL_Renderer *renderer) {
  SDL_Rect rect;
  rect.x = this->position.x;
  rect.y = this->position.y;
  rect.w = this->size;
  rect.h = this->size;
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect);
}
