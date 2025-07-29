#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

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

Vector* initializeVector(DataType datatype);
int insertElement(Vector* v, void* element, int index);
int addElementFront(Vector* v, void* element);
int addElementBack(Vector* v, void* element);
int getIndex(const Vector* v, void* element);
void* getElement(Vector* v, int index);
int removeIndex(Vector* v, int index);
int removeElement(Vector* v, void* element);
void printVector(const Vector* v);
void deleteVector(Vector* v);

#endif
