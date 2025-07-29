# c-vector

My implementation of `std::vector` in C

The functions I have implemented are:

```c
Vector* initializeVector(DataType datatype); // returns a vector pointer
int addElement(Vector* v, void* element); // returns -1 if error, 0 if no error
void printVector(Vector* v); // doesn't return anything
void deleteVector(Vector* v); // doesn't return anything 
```

I have datatype defined as an enum for the following types (pretty much all the commonly used basic types; does not support custom struct type):

```c
TYPE_INT,
TYPE_DOUBLE,
TYPE_CHAR,
TYPE_STRING
```
