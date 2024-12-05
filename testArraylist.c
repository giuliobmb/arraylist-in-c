//testArraylist.c starts here

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.c"


int main(){
    printf("\ntesting...");

    ArrayList arrayTest = createArray();

    ArrayList array =  createArray();

    printf("\narray initialised");
    
    insert(array, (void*)"ciao");
    
    printf("\nsize: %d", size(array));
    printf("\n\n%s", (char*)get(array, 0));

}


