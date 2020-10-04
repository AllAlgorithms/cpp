#include "AVL.h"
using namespace std;

//Calcule altura de um nó
int height_node(struct _Node_* node){
    if(node == NULL)
        return -1;
    else
        return node->height;
}
//Calcule o fator de balanceamento de um nó
int fatorBalanceamento_node(struct _Node_* node){
    int valor = (height_node(node->right))-(height_node(node->left));
    return valor;
}
//Calcula o maior valor
int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}
//Rotação a esquerda
AVLnode* RotationLL(AVLnode* root){
    AVLnode*node;
    node = root->left;
    root->left = node->right;
    root->height = maior(height_node(root->left),height_node(root->right)) + 1;
    node->height = maior(height_node(node->left),height_node(root)) + 1;
    root = node;
    return root;
}
//Rotação a direita
AVLnode* RotationRR(AVLnode* root){
    AVLnode* node;
    node = root->right;
    root->right = node->left;
    root->height = maior(height_node(root->left),height_node(root->right)) + 1;
    node->height = maior(height_node(node->right),height_node(root)) + 1;
    root = node;
    return root;
}
//Rotação dupla a esquerda
AVLnode* RotationLR(AVLnode* root){
    root->left = RotationRR(root->left);
    root = RotationLL(root);
    return root;
}
//Rotação dupla a direita
AVLnode* RotationRL(AVLnode* root){
    root->right = RotationLL(root->right);
    root = RotationRR(root);
    return root;
}
//Insert AVLtree
AVLnode* insert_AVLnode(AVLnode* root,Data* data){
    //árvore vazia ou nó folha
    if(root == NULL){
        AVLnode* novo;
        novo = new AVLnode[1];
        if(novo == NULL)
            return NULL;
        novo->data = data;
        novo->height = 0;
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }

    AVLnode* current = root;

    /*Balançeamento*/
    if(data->key < current->data->key){
        current->left = insert_AVLnode(current->left, data);
        if(current->left != NULL){
            if(fatorBalanceamento_node(current) <= -2){
                if(data->key < current->left->data->key)
                    root = RotationLL(root);
                else
                    root = RotationLR(root);
            }
        }
        return root;
    }else{
        if(data->key > current->data->key){
            current->right = insert_AVLnode(current->right, data);
            if(current->right != NULL){
                if(fatorBalanceamento_node(current) >= 2){
                    if(data->key > current->right->data->key)
                        root = RotationRR(root);
                    else
                        root = RotationRL(root);
                }
            }
        }
        return root;
    }
    return NULL;
}
//Query
void Query(AVLnode* root,Data** aux,string str,int* passos){
    int value = valorString(str);
    if(root != NULL){
        if(root->data->key == value){
            *aux = root->data;
        }else if(value > root->data->key){
            Query(root->right, &*aux, str, &*passos);
        }else{
            Query(root->left, &*aux, str, &*passos);
        }
    }
    *passos = *passos + 1;
}

//Destruir
void Destroy(AVLnode *t){
    if(t != NULL){
        Destroy(t->left);
        Destroy(t->right);
        t->data->linhas.clear();
        t->data->ocorrencias.clear();
        delete[]t->data;
        delete[]t;
    }
}
