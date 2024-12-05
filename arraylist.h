// -*- mode: C; eval: (auto-fill-mode 1); -*-
// arraylist.h starts here

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

struct _arraylist;

typedef struct _arraylist* ArrayList;

int insert(ArrayList array, void*);

/*
int remove(ArrayList array, int index);
*/

void* get(ArrayList array, int index);

int size(ArrayList array);

#endif //ARRAYLIST_H

// arraylist.h ends here