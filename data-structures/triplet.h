#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000
int sparse[MAX_SIZE][3];

void swap(int x, int y) {
    int i;
    for (i = 0; i < 3; i++) {
        int temp = sparse[x][i];
        sparse[x][i] = sparse[y][i];
        sparse[y][i] = temp;
    }
}
void swapvr(int x, int y) {
    int i;
    for (i = 0; i < 3; i++) {
        if(i==1)
            continue;
        int temp = sparse[x][i];
        sparse[x][i] = sparse[y][i];
        sparse[y][i] = temp;
    }
}

void init(int _row, int _col) {
    sparse[0][0] = _row;
    sparse[0][1] = _col;
    sparse[0][2] = 0;
}

void display() {
    int iter;
    printf("header(sparse matrix rows, sparse matrix columns, number of entries in sparse matrix)\n%d\t%d\t%d\nMatrix\n",
           sparse[0][0], sparse[0][1], sparse[0][2]);
    if(sparse[0][2] == 0){
        printf("EMPTY\n");
        return;
    }
    for (iter = 1; iter <= sparse[0][2]; iter++) {
        printf("%d\t%d\t%d\n", sparse[iter][0], sparse[iter][1], sparse[iter][2]);
    }
}

void insert(int val, int row, int col) {
    if (row < sparse[0][0] && col < sparse[0][1]) {
        int iter, i;
        printf("%d", sparse[1][0]);
        for (iter = 1; iter <= sparse[0][2] && sparse[iter][0] < row; iter++);
        for (; iter <= sparse[0][2] && sparse[iter][0] <= row && sparse[iter][1] < col; iter++);
        for (i = sparse[0][2]; i >= iter; i--) {
            swap(i, i + 1);
        }
        sparse[iter][0] = row;
        sparse[iter][1] = col;
        sparse[iter][2] = val;
        sparse[0][2]++;
    }
}

void delete(int row, int col) {
    if (row < sparse[0][0] && col < sparse[0][1]) {
        int iter;
        for (iter = 1; sparse[iter][0] != row && sparse[iter][1] != col; iter++);
        if(sparse[iter][0]!=row || sparse[iter][1]!=col)
            return;
        for (; iter < sparse[0][2]; iter++)
            swap(iter, iter + 1);
        sparse[0][2]--;
    }
}

void deleteRow(int row) {
    if(row < sparse[0][0]){
        int iter,offset,shift;
        for(iter = 1; sparse[iter][0] != row; iter++);
        if(sparse[iter][0] != row)
            return;
        for(offset = iter; sparse[offset][0] == row; offset++);
        shift = offset-iter;
        for(; iter <= sparse[0][2]-shift; iter++) {
            swap(iter, iter + shift);
            sparse[iter][0]--;
        }
        sparse[0][2]-=shift;
    }
}

void swapRows(int row1, int row2){
    if(row1 < sparse[0][0] && row2 < sparse[0][0] && row1!= row2) {
        int i, j;
        for(i = 1; i <= sparse[0][2]; i++){
            if(sparse[i][0] == row1){
                sparse[i][0] = row2;
            }
            else if(sparse[i][0] == row2){
                sparse[i][0] = row1;
            }
        }
        for(i=1;i<sparse[0][2];i++){
            for(j=i+1;j<=sparse[0][2];j++){
                if(sparse[i][0] > sparse[j][0]){
                    swap(i,j);
                }
                else if(sparse[i][0] == sparse[j][0] && sparse[i][1] > sparse[j][1]){
                    swap(i,j);
                }
            }
        }
    }
}
