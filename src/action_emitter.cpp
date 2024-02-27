#include "action_emitter.h"
#include "creature.h"
#include <algorithm> // Include the necessary header file for std::max

ActionEmitter::ActionEmitter()
{
    this->node = nullptr;
}

MoveSpeedEmitter::MoveSpeedEmitter(float speed) : ActionEmitter()
{
    this->speed = speed;
}

void MoveSpeedEmitter::emit(Creature *creature)
{
    creature->setSpeed(std::max(creature->max_speed, static_cast<float>(node->value)));
};

void MoveDirectionEmitter::emit(Creature *creature)
{
    creature->setAngle(node->value);
};
