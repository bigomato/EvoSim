#include "action_emitter.h"
#include "creature.h"
#include <cmath>

ActionEmitter::ActionEmitter(Node &node) : node (node) {};

void MoveSpeedEmitter::emit(Creature *creature) {
    creature->setSpeed(std::max(creature->max_speed, static_cast<float>(node.value))); // Cast node.value to float if necessary
};

void MoveDirectionEmitter::emit(Creature *creature) {
    creature->setAngle(node.value);
};

