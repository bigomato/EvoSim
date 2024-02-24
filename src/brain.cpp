#include "brain.h"

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>

Brain::Brain()
{
  nodes = std::vector<Node>();
  connections = std::vector<Connection>();
}

Brain::~Brain()
{
  nodes.clear();
  connections.clear();
}

void Brain::addNode(const Node *node) { nodes.push_back(*node); }

void Brain::addConnection(const Connection &connection)
{
  connections.push_back(connection);
}

string Brain::generatePythonCode()
{
  // this function generates code that can be used to create a neural network in python.
  // the code is saved in a file.
  // the return value is the name of the file where the code is saved.
  // Example:
  // brain = Brain()
  // brain.add_node(Node(1, 'input'))
  // brain.add_node(Node(2, 'input'))
  // brain.add_node(Node(3, 'hidden'))
  // brain.add_node(Node(4, 'output'))
  // brain.add_connection(Connection(1, 1, 3))
  // brain.add_connection(Connection(2, 2, 3))
  // brain.add_connection(Connection(3, 3, 4))

  std::unordered_map<int, std::string> node_types = {
      {0, "input"},
      {1, "hidden"},
      {2, "output"},
  };

  std::string code = "from brain import Brain\n";
  code += "from node import Node\n";
  code += "from connection import Connection\n";
  code += "brain = Brain()\n";
  for (auto &node : nodes)
  {
    code += "brain.add_node(Node(" + std::to_string(node.id) + ", '" + node_types[node.type] + "'))\n";
  }
  for (auto &connection : connections)
  {
    code += "brain.add_connection(Connection(" + std::to_string(connection.id) + ", " + std::to_string(connection.in) + ", " + std::to_string(connection.out) + "))\n";
  }

  std::ofstream out;
  out.open("brains.py");
  out << code;
  out.close();
  return "brain.py";
}

Node *Brain::getNode(int id)
{
  for (auto &node : nodes)
  {
    if (node.id == id)
    {
      return &node;
    }
  }
  return nullptr;
}

void Brain::input_node_values(const std::vector<NodeValue> &node_values)
{
  for (auto &node_value : node_values)
  {
    Node *node = getNode(node_value.id);
    if (node != nullptr)
    {
      node->value = node_value.value;
    }
    else
    {
      printf("Node with id %d not found\n", node_value.id);
    }
  }
}

void Brain::feedForward()
{
  for (auto &node : nodes)
  {
    if (node.type == 0)
    { // input node
      continue;
    }

    double sum = 0;
    for (auto &connection : connections)
    {
      if (connection.out == node.id)
      {
        Node *inNode = getNode(connection.in);
        if (inNode == nullptr)
        {
          printf("Node with id %d not found\n", connection.in);
          continue;
        }
        sum += inNode->value * connection.weight;
      }
    }
    node.value = node.activationFunction(sum + node.bias);
  }
}
