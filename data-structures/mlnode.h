#include <stdio.h>
#include <stdlib.h>

struct MLNode {
    int row, col, info;
    struct MLNode *nextRow, *nextCol;
};
typedef struct MLNode MLNODE;

MLNODE *init(int row, int col) {
    int i;
    MLNODE *head = (MLNODE *) malloc(sizeof(MLNODE));
    head->row = head->col = -1;
    head->nextRow = head;
    head->nextCol = head;
    MLNODE *rowIter = head, *colIter = head;
    for (i = 0; i < row; i++) {
        MLNODE *rowHeader = (MLNODE *) malloc(sizeof(MLNODE));
        rowHeader->row = i;
        rowHeader->col = -1;
        rowHeader->nextRow = head;
        rowHeader->nextCol = rowHeader;
        rowIter->nextRow = rowHeader;
        rowIter = rowIter->nextRow;
    }
    rowIter->nextRow = head;
    for (i = 0; i < col; i++) {
        MLNODE *colHeader = (MLNODE *) malloc(sizeof(MLNODE));
        colHeader->row = -1;
        colHeader->col = i;
        colHeader->nextRow = colHeader;
        colHeader->nextCol = head;
        colIter->nextCol = colHeader;
        colIter = colIter->nextCol;
    }
    colIter->nextCol = head;
    return head;
}

MLNODE *topOf(MLNODE *head, MLNODE *key) {
    if (head == NULL) {
        printf("Matrix is empty\n");
        return head;
    }
    MLNODE *p = head->nextCol, *q;
    while (p->col != key->col) {
        p = p->nextCol;
        if (p == head) {
            printf("Couldn't find node %d\n", key->info);
            return head;
        }
    }
    q = p;
    p = p->nextRow;
    while (p->row != -1 && p->row < key->row) {
        q = p;
        p = p->nextRow;
    }
    return q;
}

MLNODE *leftOf(MLNODE *head, MLNODE *key) {
    if (head == NULL) {
        printf("Matrix is empty\n");
        return head;
    }
    MLNODE *p = head->nextRow, *q;
    while (p->row != key->row) {
        p = p->nextRow;
        if (p == head) {
            printf("Couldn't find node %d\n", key->info);
            return head;
        }
    }
    q = p;
    p = p->nextCol;
    while (p->col != -1 && p->col < key->col) {
        q = p;
        p = p->nextCol;
    }
    return q;
}

void display(MLNODE *head) {
    MLNODE *p = head->nextRow;
    MLNODE *q;
    while (p != head) {
        printf("row:%d\t", 1 + p->row);
        q = p->nextCol;
        while (q != p) {
            printf("[(%d,%d):%d] ", q->row + 1, q->col + 1, q->info);
            q = q->nextCol;
        }
        printf("\n");
        p = p->nextRow;
    }
}

MLNODE *deletion(MLNODE *head, int key) {
    if (head == NULL) {
        printf("Matrix is empty\n");
        return head;
    }
    MLNODE *rowIter = head->nextRow, *colIter;
    while (rowIter != head) {
        colIter = rowIter->nextCol;
        while (colIter != rowIter && colIter->info != key) {
            colIter = colIter->nextCol;
        }
        if (colIter->info == key) {
            MLNODE *top = topOf(head, colIter), *left = leftOf(head, colIter);
            top->nextRow = colIter->nextRow;
            left->nextCol = colIter->nextCol;
            free(colIter);
        }
        rowIter = rowIter->nextRow;
    }
    return head;
}

MLNODE *deletionOfAddr(MLNODE *head, MLNODE *key) {
    if (head == NULL) {
        printf("Matrix is empty\n");
        return head;
    }
    MLNODE *rowIter = head->nextRow, *colIter;
    while (rowIter != head) {
        colIter = rowIter->nextCol;
        while (colIter != rowIter && colIter != key) {
            colIter = colIter->nextCol;
        }
        if (colIter == key) {
            MLNODE *top = topOf(head, colIter), *left = leftOf(head, colIter);
            top->nextRow = colIter->nextRow;
            left->nextCol = colIter->nextCol;
            free(colIter);
        }
        rowIter = rowIter->nextRow;
    }
    return head;
}

MLNODE *insertion(MLNODE *head, int _info, int _r, int _c) {
    if (head == NULL) {
        printf("Matrix is empty\n");
        return head;
    }
    MLNODE *mlnode = (MLNODE *) malloc(sizeof(MLNODE));
    mlnode->info = _info;
    mlnode->row = _r;
    mlnode->col = _c;
    MLNODE *left = leftOf(head, mlnode), *top = topOf(head, mlnode);
    if (left == head || top == head) {
        printf("stoping insertion...");
        free(mlnode);
        return head;
    }
    mlnode->nextRow = top->nextRow;
    top->nextRow = mlnode;
    mlnode->nextCol = left->nextCol;
    left->nextCol = mlnode;
    return head;
}

MLNODE *deleteRow(MLNODE *head, int _row) {
    if (head == NULL) {
        printf("Matrix is empty\n");
        return head;
    }
    MLNODE *rowIter = head->nextRow, *colIter, *prev = head;
    while (rowIter->row != _row) {
        if (rowIter == head) {
            printf("Couldn't find row in matrix\n");
            return head;
        }
        prev = rowIter;
        rowIter = rowIter->nextRow;
    }
    colIter = rowIter->nextCol;
    while (colIter != rowIter) {
        MLNODE *top = topOf(head, colIter), *del;
        top->nextRow = colIter->nextRow;
        del = colIter;
        colIter = colIter->nextCol;
        free(del);
    }
    prev->nextRow = rowIter->nextRow;
    MLNODE *del = rowIter;
    rowIter = rowIter->nextRow;
    free(del);
    while (rowIter != head) {
        rowIter->row--;
        colIter = rowIter->nextCol;
        while (colIter != rowIter) {
            colIter->row--;
            colIter = colIter->nextCol;
        }
        rowIter = rowIter->nextRow;
    }
    return head;
}

MLNODE *swapRows(MLNODE *head, int _row1, int _row2) {
    if (head == NULL) {
        printf("Matrix is empty\n");
        return head;
    }
    MLNODE *rowIter1 = head->nextRow, *rowIter2 = head->nextRow;
    while (rowIter1->row != _row1) {
        if (rowIter1 == head) {
            printf("Couldn't find row %d in matrix\n",_row1);
            return head;
        }
        rowIter1 = rowIter1->nextRow;
    }
    while (rowIter2->row != _row2) {
        if (rowIter2 == head) {
            printf("Couldn't find row %d in matrix\n",_row1);
            return head;
        }
        rowIter2 = rowIter2->nextRow;
    }
    rowIter1 = rowIter1->nextCol;
    rowIter2 = rowIter2->nextCol;
    while (rowIter1->col != -1 && rowIter2->col != -1) {
        if (rowIter1->col == rowIter2->col) {
            int temp = rowIter1->info;
            rowIter1->info = rowIter2->info;
            rowIter2->info = temp;
            rowIter1 = rowIter1->nextCol;
            rowIter2 = rowIter2->nextCol;
        } else if (rowIter1->col < rowIter2->col) {
            head = insertion(head, rowIter1->info, rowIter2->row, rowIter1->col);
            MLNODE *del = rowIter1;
            rowIter1 = rowIter1->nextCol;
            head = deletionOfAddr(head, del);
            free(del);
        } else if (rowIter1->col > rowIter2->col) {
            head = insertion(head, rowIter2->info, rowIter1->row, rowIter2->col);
            MLNODE *del = rowIter2;
            rowIter2 = rowIter2->nextCol;
            head = deletionOfAddr(head, del);
            free(del);
        }
    }
    while (rowIter1->col != -1) {
        head = insertion(head, rowIter1->info, rowIter2->row, rowIter1->col);
        MLNODE *del = rowIter1;
        rowIter1 = rowIter1->nextCol;
        head = deletionOfAddr(head, del);
        free(del);
    }
    while (rowIter2->col != -1) {
        head = insertion(head, rowIter2->info, rowIter1->row, rowIter2->col);
        MLNODE *del = rowIter2;
        rowIter2 = rowIter2->nextCol;
        head = deletionOfAddr(head, del);
        free(del);
    }
    return head;
}
