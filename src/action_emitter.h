#ifndef ACTION_EMITTER_H
#define ACTION_EMITTER_H

#include "world.h"
#include "creature.h"

class Creature;

class ActionEmitter
{
public:
    ActionEmitter();

    virtual void emit(Creature *creature) = 0;
    void setNode(Node *node) { this->node = node; }
    void setId(int id) { this->id = id; }
    Node *getNode() { return this->node; }

protected:
    Node *node;
    int id;
};

class MoveSpeedEmitter : public ActionEmitter
{
public:
    MoveSpeedEmitter(float speed);

    void emit(Creature *creature);

private:
    float speed;
};

class MoveDirectionEmitter : public ActionEmitter
{
public:
    MoveDirectionEmitter(vec2<float> direction);

    void emit(Creature *creature);

private:
    vec2<float> direction;
};

#endif