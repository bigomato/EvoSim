#ifndef NODE_H
#define NODE_H

class Node {
public:
  Node();
  Node(int id, int type, double value, double bias,
       double (*activationFunction)(double));

  int id;
  int type;
  double value;
  double bias;
  double (*activationFunction)(double);
};

#endif