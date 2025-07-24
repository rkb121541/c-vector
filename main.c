#include <stdlib.h>

typedef enum { TYPE_INT, TYPE_FLOAT } DataType;

typedef struct {
  DataType datatype;
  int length;
  int capacity;
} Vector;

Vector* initializeVector(char* name, DataType datatype) {
  Vector* v = malloc(sizeof(Vector));
  v->length = 0;
  v->datatype = datatype;
  v->capacity = 4;
  return v;
}

void addElement(Vector* vector, void* element) {
  
}

void deleteVector(Vector* vector) {
  free(vector);
}

int main(int argc, char *argv[]) {
  initializeVector("v", TYPE_INT);
  return 0;
}
