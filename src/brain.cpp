#include "brain.h"

#include <stdio.h>
#include <unordered_map>
#include <vector>

Brain::Brain() {
  nodes = std::vector<Node>();
  connections = std::vector<Connection>();
}

Brain::~Brain() {
  nodes.clear();
  connections.clear();
}

void Brain::addNode(const Node &node) { nodes.push_back(node); }

void Brain::addConnection(const Connection &connection) {
  connections.push_back(connection);
}

Node *Brain::getNode(int id) {
  for (auto &node : nodes) {
    if (node.id == id) {
      return &node;
    }
  }
  return nullptr;
}

void Brain::input_node_values(const std::vector<NodeValue> &node_values) {
  for (auto &node_value : node_values) {
    Node *node = getNode(node_value.id);
    if (node != nullptr) {
      node->value = node_value.value;
    } else {
      printf("Node with id %d not found\n", node_value.id);
    }
  }
}

void Brain::feedForward() {
  for (auto &node : nodes) {
    if (node.type == 0) { // input node
      continue;
    }

    double sum = 0;
    for (auto &connection : connections) {
      if (connection.out == node.id) {
        Node *inNode = getNode(connection.in);
        if (inNode == nullptr) {
          printf("Node with id %d not found\n", connection.in);
          continue;
        }
        sum += inNode->value * connection.weight;
      }
    }
    node.value = node.activationFunction(sum + node.bias);
  }
}
