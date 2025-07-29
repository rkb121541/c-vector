# c-vector

My implementation of `std::vector` in C

The functions I have implemented are:

```c
Vector* initializeVector(DataType datatype);
int insertElement(Vector* v, void* element, int index); // returns -1 if error, 0 if no error
int addElementFront(Vector* v, void* element); // returns -1 if error, 0 if no error
int addElementBack(Vector* v, void* element); // returns -1 if error, 0 if no error
int getIndex(const Vector* v, void* element); // returns the index where the element is first found
void* getElement(Vector* v, int index); // returns the element at the specified index
int removeIndex(Vector* v, int index); // returns -1 if error, 0 if no error
int removeElement(Vector* v, void* element); // returns -1 if error, 0 if no error
void printVector(Vector* v);
void deleteVector(Vector* v);
```

I have datatype defined as an enum for the following types (pretty much all the commonly used basic types; does not support custom struct type):

```c
TYPE_INT,
TYPE_DOUBLE,
TYPE_CHAR,
TYPE_STRING
```
