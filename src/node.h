#include <functional>
#include <map>
#include <algorithm>
#include <cmath>
#ifndef NODE_H
#define NODE_H

class Node
{
public:
     Node(int type, double bias) : id(-1), type(type), value(0), bias(bias), activationFunction(0){};
     Node(int id, int type, double value, double bias,
          int activationFunction);
     Node(int type, double bias, int activationFunction);

     int id;
     int type;
     double value;
     double bias;
     int activationFunction;

     static const std::map<int, std::function<double(double)>> func_map;

     double activate(double x);
};

#endif