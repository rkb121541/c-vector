#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  TYPE_INT,
  TYPE_DOUBLE,
  TYPE_CHAR,
  TYPE_STRING
} DataType;

typedef struct {
  int length;
  int capacity;
  size_t elemSize;
  void* data;
  DataType datatype;
} Vector;

Vector* initializeVector(DataType datatype) {
  Vector* v = malloc(sizeof(Vector));
  if (!v) {
    printf("ERROR: malloc failed to initialize v\n");
    return NULL;
  }
  v->length = 0;
  v->capacity = 4;
  switch (datatype) {
    case TYPE_INT:
      v->elemSize = sizeof(int);
      break;
    case TYPE_DOUBLE:
      v->elemSize = sizeof(double);
      break;
    case TYPE_CHAR:
      v->elemSize = sizeof(char);
      break;
    case TYPE_STRING:
      v->elemSize = sizeof(char*);
      break;
  }
  v->data = malloc(v->capacity * v->elemSize);
  if (!v->data) {
    printf("ERROR: malloc failed to initialize v data\n");
    free(v);
    return NULL;
  }
  return v;
}

int addElement(Vector* v, void* element) {
  if (v->length == v->capacity) {
    int newCapacity = v->capacity * 2;
    void* newData = realloc(v->data, newCapacity * v->elemSize);
    if (!newData) {
      printf("ERROR: realloc failed for adding new element\n");
      return -1;
    }
    v->data = newData;
    v->capacity = newCapacity;
  }
  void* dest = (char*)v->data + (v->length * v->elemSize);
  memcpy(dest, element, v->elemSize);
  v->length++;
  return 0;
}

void deleteVector(Vector* v) {
  free(v->data);
  free(v);
}

void printVector(Vector* v) {
  printf("[");
  for (int i = 0; i < v->length; i++) {
    void* elem = (char*)v->data + (i * v->elemSize);
    switch (v->datatype) {
      case TYPE_INT:
        printf("%d", *(int*)elem);
        break;
      case TYPE_DOUBLE:
        printf("%.4f", *(double*)elem);
        break;
      case TYPE_CHAR:
        printf("%c", *(char*)elem);
        break;
      case TYPE_STRING: 
        printf("%s", *(char**)elem);
        break;
    }
    if (i != v->length - 1)
      printf(", ");
  }
  printf("]\n");
}

int main(int argc, char *argv[]) {
  Vector *v = initializeVector(TYPE_INT);
  for (int i = 0; i < 10; i++) {
    addElement(v, &i);
  }
  printVector(v);
  deleteVector(v);
  return 0;
}
