#ifndef BRAIN_H
#define BRAIN_H

#include <map>
#include <vector>

#include "connection.h"
#include "node.h"

using std::map;
using std::vector;

struct NodeValue {
  int id;
  double value;
};

class Brain {
public:
  Brain();
  ~Brain();

  void input_node_values(const vector<NodeValue> &node_values);
  void feedForward();

  void addNode(const Node &node);
  void addConnection(const Connection &connection);

private:
  vector<Node> nodes;
  vector<Connection> connections;

  Node *getNode(int index);
};

#endif