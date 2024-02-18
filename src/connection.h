#ifndef CONNECTION_H
#define CONNECTION_H

class Connection {
public:
  Connection(int id, int in, int out, double weight);

  int id, in, out;
  double weight;
};

#endif