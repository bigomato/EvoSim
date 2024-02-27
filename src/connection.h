#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
public:
  Connection(int id, int in, int out, double weight) : id(id), in(in), out(out), weight(weight){};
  Connection(int in, int out, double weight) : in(in), out(out), weight(weight), id(-1){};

  int id, in, out;
  double weight;
};

#endif