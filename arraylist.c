// -*- mode: C; -*-
// arraylist.c starts here
// implementation of a string ArrayList

#ifndef ARRAYLIST_C_
#define ARRAYLIST_C_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arraylist.h"

struct _arraylist {
  void** data;
  int size;
  size_t byte_size;
};

int reallocate(ArrayList array);
void printArrayList(ArrayList array);

// initialises an empty arraylist with parameters set to 0
//
ArrayList createArray(){ 
  ArrayList array = malloc(sizeof(struct _arraylist));
  array->size = 0;
  array->byte_size = 0;
  array->data = NULL;
  return array;
}

int insert(ArrayList array, void* data){
  if(data == NULL){ return -1; } // in case new data is not present
  
  // increment of the number of pointers (each pointer will have a different size)
  int new_size = array->size + 1;
  
  //printf("new size = %d", new_size);
  void** new_data = malloc(sizeof(void*) * new_size); // new pointer of pointers with a new last pointer that will contain new data :)
  
  
  if(new_data == NULL){ return -2; } // in case is not possible to allocate memory for the new data
  
  for(int i=0, j=0; i < array->size; i++){
      if(array->data[i] != NULL){
        new_data[j] = array->data[i];
        j++;
      }
    }
  
  free(array->data);
  new_data[new_size-1] = data;
  
  
  array->size++;
  array->data = new_data;
  array->byte_size = sizeof(void*) * new_size;
 
}

void* get(ArrayList array, int index){
  if(array->data[index] == NULL)
    return NULL;
  return array->data[index];
}

int size(ArrayList array){
  return array->size;
}


int removeElement(ArrayList array, int index){
  if(index>= array->size || index<0){ return -1; }
  array->data[index] = NULL;
  int r = reallocate(array);
  if(r != 0) {fprintf(stderr, "\nError [CODE: %d] while reallocating, in remove function", r);}
  return 0;
}

int reallocate(ArrayList array){
  int size = 0;
  for(int i=0; i < array->size; i++){
      if(array->data[i] != NULL){
        size++;
      }
    }

  void** new_data = malloc(sizeof(void*) * size); // new pointer of pointers with a new last pointer that will contain new data :)
  if(new_data == NULL){ return -2; } // in case is not possible to allocate memory for the new data
  
  for(int i=0, j=0; i < array->size; i++){
      if(array->data[i] != NULL){
        new_data[j] = array->data[i];
        j++;
      }
    }
  
  free(array->data);
  
  array->data = new_data;
  array->size = size;
  return 0;
}


void printar(ArrayList array, char type[]){
  printf("\nArrayList = {\n");
  for(int i=0; i < array->size; i++){
      printf(type, array->data[i]);
      printf(", ");
    }
    printf("\n }");

}

#endif //ARRAYLIST_C_

// arraylist.c ends here
