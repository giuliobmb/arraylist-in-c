//testArraylist.c starts here

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.c"


int main(){

    ArrayList array =  createArray();

    printf("\narray initialised\n");
    
    insert(array, (void*)"ciao");
    printar(array, "%s");
    
    insert(array, (void*)"mondo");
    insert(array, (void*)"terza");
    printar(array, "%s");
    
    printf("\n\nsize: %d", size(array));
    
    printf("\n\n%s", (char*)get(array, 2));
    
    removeElement(array, 0);
    removeElement(array, 0);
    
    printf("\n\nsize: %d", size(array));
    
    insert(array, (void*)"quarto");
    
    printar(array, "%s");
    
    
}


