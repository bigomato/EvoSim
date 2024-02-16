#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

#include "world.h"

using std::cout;
using std::endl;

int main() {
  World world;
  world.startSimulation();
  return 0;
}
