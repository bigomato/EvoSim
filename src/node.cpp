#include "node.h"

Node::Node(int type, double bias, int activationFunction)
{
    this->type = type;
    this->bias = bias;
    this->activationFunction = activationFunction;
    this->id = -1;
}

const std::map<int, std::function<double(double)>> Node::func_map = {
    {0, [](double x)
     { return x; }}, // Identity
    {1, [](double x)
     { return 1 / (1 + std::exp(-x)); }}, // Sigmoid
    {2, [](double x)
     { return std::tanh(x); }}, // Tanh
    {3, [](double x)
     { return std::max(0.0, x); }}, // ReLU
    {4, [](double x)
     { return (x > 0) ? 1 : 0; }}}; // Step

double Node::activate(double x)
{
    return func_map.at(activationFunction)(x);
}