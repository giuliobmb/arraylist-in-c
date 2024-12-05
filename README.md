# ArrayList C Implementation

This repository contains a simple and efficient implementation of a dynamic ArrayList in C, designed to store and manage a collection of pointers (`void*`). It provides basic functionality for dynamic memory allocation, insertion, retrieval, and querying the size of the list.

## Features

- **Dynamic Resizing**: The ArrayList automatically resizes as new elements are inserted.
- **Flexible Data Types**: Can store pointers to any data type (`void*`).
- **Core Operations**:
  - `createArray()` – Initializes an empty ArrayList.
  - `insert()` – Adds new data to the ArrayList.
  - `get()` – Retrieves data at a given index.
  - `size()` – Returns the current number of elements in the ArrayList.

## Example Usage

```c
#include "arraylist.h"

int main() {
    // Create a new ArrayList
    ArrayList list = createArray();
    
    // Insert an integer into the list
    int a = 10;
    insert(list, &a);
    
    // Retrieve the integer from the list
    int* retrieved = (int*)get(list, 0);
    printf("Retrieved value: %d\n", *retrieved);
    
    // Get the size of the ArrayList
    printf("List size: %d\n", size(list));
    
    return 0;
}
