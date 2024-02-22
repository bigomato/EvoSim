#ifndef ACTION_EMITTER_H
#define ACTION_EMITTER_H

#include "world.h"
#include "creature.h"

class ActionEmitter {
    public:
        ActionEmitter(Node &node);

        virtual void emit(Creature *creature) = 0;
    protected:
        Node &node;
};

class MoveSpeedEmitter : public ActionEmitter {
    public:
        MoveSpeedEmitter(Node &node, float speed);

        void emit(Creature *creature);
    private:
        float speed;
};

class MoveDirectionEmitter : public ActionEmitter {
    public:
        MoveDirectionEmitter(Node &node, vec2<float> direction);

        void emit(Creature *creature);
    private:
        vec2<float> direction;
};

#endif