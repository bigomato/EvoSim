#ifndef NODE_H
#define NODE_H

class Node
{
public:
     Node(int type, double bias) : id(-1), type(type), value(0), bias(bias), activationFunction(nullptr){};
     Node(int id, int type, double value, double bias,
          double (*activationFunction)(double));
     Node(int type, double bias,
          double (*lambda)(double x));

     int id;
     int type;
     double value;
     double bias;
     double (*activationFunction)(double x);
};

#endif