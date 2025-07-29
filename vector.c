#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

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
  memset(v->data, 0, v->capacity * v->elemSize);
  return v;
}

int insertElement(Vector* v, void* element, int index) {
  if (index < 0 || index > v->length) {
    printf("ERROR: Index out of bounds\n");
    return -1;
  }
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
  void* dest = (char*)v->data + ((index + 1) * v->elemSize);
  void* src = (char*)v->data + (index * v->elemSize);
  size_t bytesToMove = (v->length - index) * v->elemSize;
  memmove(dest, src, bytesToMove);
  memcpy((char*)v->data + (index * v->elemSize), element, v->elemSize);
  v->length++;
  return 0;
}

int addElementFront(Vector* v, void* element) {
  return insertElement(v, element, 0);
}

int addElementBack(Vector* v, void* element) {
  return insertElement(v, element, v->length);
}

int getIndex(const Vector* v, void* element) {
  for (int i = 0; i < v->length; i++) {
    void* elem = (char*)v->data + (i * v->elemSize);
    int cmp = 0;
    switch (v->datatype) {
      case TYPE_INT:
        cmp = (*(int*)elem == *(int*)element);
        break;
      case TYPE_DOUBLE:
        cmp = (*(double*)elem == *(double*)element);
        break;
      case TYPE_CHAR:
        cmp = (*(char*)elem == *(char*)element);
        break;
      case TYPE_STRING:
        cmp = (strcmp(*(char**)elem, *(char**)element) == 0);
        break;
    }
    if (cmp == 1) {
      return i;
    }
  }
  return -1;
}

void* getElement(Vector* v, int index) {
  if (index < 0 || index >= v->length) {
    printf("ERROR: Index out of bounds\n");
    return NULL;
  }
  return (char*)v->data + (index * v->elemSize);
}

int removeIndex(Vector* v, int index) {
  if (index < 0 || index >= v->length) {
    printf("ERROR: Index out of bounds\n");
    return -1;
  }
  void* dest = (char*)v->data + (v->elemSize * index);
  void* src = (char*)v->data + (v->elemSize * (index + 1));
  size_t bytesToMove = (v->length - (index + 1)) * v->elemSize;
  memmove(dest, src, bytesToMove);
  v->length--;
  return 0;
}

int removeElement(Vector* v, void* element) {
  int index = getIndex(v, element);
  if (index == -1) {
    printf("ERROR: Element not in vector\n");
    return -1;
  }
  return removeIndex(v, index);
}

void printVector(const Vector* v) {
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

void deleteVector(Vector* v) {
  free(v->data);
  free(v);
}
