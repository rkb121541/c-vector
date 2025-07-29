#include "vector.h"
int main(int argc, char *argv[]) {
  Vector* v = initializeVector(TYPE_INT);
  for (int i = 0; i < 5; i++) {
    addElementFront(v, &i);
    printVector(v);
  }
  deleteVector(v);
  return 0;
}
