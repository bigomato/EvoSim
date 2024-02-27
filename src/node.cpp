#include "node.h"

Node::Node(int type, double bias, double (*lambda)(double x))
{
    this->type = type;
    this->bias = bias;
    this->activationFunction = activationFunction;
    this->id = -1;
}