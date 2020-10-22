#include "RedBlack.h"

//Rotação a esquerda
void rightRotate(RBnode** root, RBnode* x){
    RBnode* y = x->left;
    x->left = y->right;
    if(y->right != NULL)
        y->right->dad = x;
    y->dad = x->dad;
    if (x->dad == NULL){
        *root = y;
    }else{
        if(x == x->dad->right)
            x->dad->right = y;
        else
            x->dad->left = y;
    }
    y->right = x;
    x->dad = y;
}
//Rotação a direita
void leftRotate(RBnode** root,RBnode* x){
    RBnode* y = x->right;
    x->right = y->left;
    if(y->left != NULL)
        y->left->dad = x;
    y->dad = x->dad;
    if(x->dad == NULL)
        *root = y;
    else{
        if(x == x->dad->left)
            x->dad->left = y;
        else
            x->dad->right = y;
    }
    y->left = x;
    x->dad = y;
}

//color 1-red 0-black
void fix_insert(RBnode **root, RBnode *node){
    RBnode* z = node;
    while((*root != z) && (z->dad->color==1)){
        if(z->dad == z->dad->dad->left){
            RBnode* y = z->dad->dad->right;
            /*Caso 1: Um nó x está sendo inserido, e seu tio é
            vermelho então é necessário recolorir o pai, o tio
            o avô*/
            if((y!=NULL) && (y->color == 1)){
                z->dad->color = 0;
                y->color = 0;
                z->dad->dad->color = 1;
                z = z->dad->dad;
            }else{
                if(z == z->dad->right){
                    /*Caso 2:irmão preto e pai vermelho*/
                    z = z->dad;
                    leftRotate(&*root,z);
                }
                /*Caso 3:pai vermelho, irmão preto, avô preto*/
                z->dad->color = 0;
                z->dad->dad->color = 1;
                rightRotate(&*root,z->dad->dad);
            }
        }else{
            RBnode* y = z->dad->dad->left;
            if((y!=NULL) && (y->color == 1)){
                /*caso 4*/
                z->dad->color = 0;
                y->color = 0;
                z->dad->dad->color = 1;
                z = z->dad->dad;
            }else{
                /*Caso 5:*/
                if(z == z->dad->left){
                    z = z->dad;
                    rightRotate(&*root,z);
                }
                /*Caso 6:pai vermelho, avô preto, tio preto*/
                z->dad->color = 0;//pai fica preto
                z->dad->dad->color = 1;//avô fica vermelho
                leftRotate(&*root, z->dad->dad);//gera uma rotação a esquerda
            }
        }
    }
}

void RB_Insert(RBnode** root, Data* data){
    RBnode* y = NULL;
    RBnode* x = *root;
    while(x != NULL){
        y = x;
        if(data->key < x->data->key)
            x = x->left;
        else
            x = x->right;
    }
    RBnode* newnode = new RBnode[1];
    if(newnode != NULL){
        newnode->data = data;
        newnode->color = 1;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->dad = y;
    }
    if(y == NULL){
        *root = newnode;
    }else{
        if(data->key < y->data->key)
            y->left = newnode;
        else
            y->right = newnode;
    }
    fix_insert(&*root, newnode);
    (*root)->color = 0;
}

//Query
void RBQuery(RBnode* root,Data** aux,string str,int* passos){
    int value = valorString(str);
    if(root != NULL){
        if(root->data->key == value){
            *aux = root->data;
        }else if(value > root->data->key){
            RBQuery(root->right, &*aux, str, &*passos);
        }else{
            RBQuery(root->left, &*aux, str, &*passos);
        }
    }
    *passos = *passos+1;
}

//Destruir
void RBDestroy(RBnode *t){
    if(t != NULL){
        RBDestroy(t->left);
        RBDestroy(t->right);
        t->data->linhas.clear();
        t->data->ocorrencias.clear();
        delete[]t->data;
        delete[]t;
    }
}
