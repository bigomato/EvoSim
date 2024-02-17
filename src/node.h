#ifndef NODE_H
#define NODE_H

class Node {
public:
  Node();
  ~Node();

  int getType();
  float getValue();

  void setType(int type);
  void setValue(float value);

private:
  int id;
  int type;
  float value;
  float bias;
};

#endif