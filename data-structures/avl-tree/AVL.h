#ifndef _AVL_H_
#define _AVL_H_
#include "structs.h"

typedef struct _Node_{
    struct _data_ *data;
    int height;
    struct _Node_ *left;
    struct _Node_ *right;
} AVLnode;

AVLnode* insert_AVLnode(AVLnode* root,Data* data);
void Query(AVLnode* root,Data** aux,string str, int* passos);
void Destroy(AVLnode *t);

#endif

