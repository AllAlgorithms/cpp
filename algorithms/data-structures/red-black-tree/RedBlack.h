#ifndef _REDBLACK_H_
#define _REDBLACK_H_
#include "structs.h"

    typedef struct _RBNode_{
        int color;
        struct _data_ *data;
        struct _RBNode_ *left, *right, *dad;
    } RBnode;

    extern void RB_Insert(RBnode** root, Data* data);
    extern void RBQuery(RBnode* root,Data** aux,string str,int* passos);
    void RBDestroy(RBnode *t);
#endif
