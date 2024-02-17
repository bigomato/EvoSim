#ifndef BRAIN_H
#define BRAIN_H

#include <map>
#include <vector>

#include "connection.h"
#include "node.h"

using std::map;
using std::vector;

class Brain {
public:
  Brain();
  ~Brain();

  map<int, float> feed_forward(map<int, float>);

  int addNode(Node node);
  int addConnection(Connection connection);

private:
  vector<Node> nodes;
  vector<Connection> connections;

  Node getNode(int index);
  Connection getConnection(int index);
};

#endif