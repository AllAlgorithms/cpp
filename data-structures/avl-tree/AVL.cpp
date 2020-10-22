#include "AVL.h"
using namespace std;

//Calculate the height of a node.
int height_node(struct _Node_* node){
    if(node == NULL)
        return -1;
    else
        return node->height;
}

//Calculate the balancing factor of a node.
int fatorBalanceamento_node(struct _Node_* node){
    int valor = (height_node(node->right))-(height_node(node->left));
    return valor;
}

//Rotate left
AVLnode* RotationLL(AVLnode* root) {
    AVLnode* node;
    node = root->left;
    root->left = node->right;
    root->height = std::max(height_node(root->left),height_node(root->right)) + 1;
    node->height = std::max(height_node(node->left),height_node(root)) + 1;
    root = node;
    return root;
}

//Rotate right
AVLnode* RotationRR(AVLnode* root) {
    AVLnode* node;
    node = root->right;
    root->right = node->left;
    root->height = std::max(height_node(root->left), height_node(root->right)) + 1;
    node->height = std::max(height_node(node->right), height_node(root)) + 1;
    root = node;
    return root;
}

//Rotate left twice
AVLnode* RotationLR(AVLnode* root){
    root->left = RotationRR(root->left);
    root = RotationLL(root);
    return root;
}

//Rotate right twice
AVLnode* RotationRL(AVLnode* root){
    root->right = RotationLL(root->right);
    root = RotationRR(root);
    return root;
}

//Insert AVLtree
AVLnode* Insert_AVLnode(AVLnode* root,Data* data){
    //If tree is empty or leaf.
    if(root == NULL) {
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

    /*Balancing*/
    if(data->key < current->data->key) {
        current->left = insert_AVLnode(current->left, data);
        if(current->left != NULL) {
            if(fatorBalanceamento_node(current) <= -2) {
                if(data->key < current->left->data->key)
                    root = RotationLL(root);
                else
                    root = RotationLR(root);
            }
        }
        return root;
    } else {
        if(data->key > current->data->key) {
            current->right = insert_AVLnode(current->right, data);
            if(current->right != NULL) {
                if(fatorBalanceamento_node(current) >= 2) {
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
void Query(AVLnode* root, Data** aux, string str, int* passos) {
    int value = valorString(str);
    if(root != NULL) {
        if(root->data->key == value) {
            *aux = root->data;
        } else if(value > root->data->key) {
            Query(root->right, &*aux, str, &*passos);
        } else {
            Query(root->left, &*aux, str, &*passos);
        }
    }
    *passos = *passos + 1;
}

//Destructor
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
