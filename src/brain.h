#ifndef BRAIN_H
#define BRAIN_H

#include <map>
#include <vector>

#include "connection.h"
#include "node.h"
#include <string>

using std::map;
using std::string;
using std::vector;
struct NodeValue
{
  int id;
  double value;
};

class Brain
{
public:
  Brain();
  ~Brain();

  void input_node_values(const vector<NodeValue> &node_values);
  void feedForward();

  void addNode(Node *node);
  void addConnection(const Connection &connection);
  string generatePythonCode();

private:
  vector<Node> nodes;
  vector<Connection> connections;

  Node *getNode(int index);
};

#endif