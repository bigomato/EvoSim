#ifndef CONNECTION_H
#define CONNECTION_H

class Connection {
public:
  Connection(int in, int out, float weight);
  ~Connection();

  int getIn();
  int getOut();
  float getWeight();

  void setWeight(float weight);

private:
  int in, out;
  float weight;
};

#endif