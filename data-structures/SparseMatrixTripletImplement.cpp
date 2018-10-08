#include "triplet.h"

int main() {
    int c, val, row, col;
    while (1) {
        printf("--------------------------------\n");
        printf("1. Initialize Sparse Matrix(Triplet).\n");
        printf("2. Display Matrix.\n");
        printf("3. Insert element in Sparse Matrix.\n");
        printf("4. Delete element in Sparse Matrix.\n");
        printf("10. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter number of rows to insert:");
                scanf("%d", &row);
                printf("Enter number of columns to insert:");
                scanf("%d", &col);
                init(row, col);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter value to insert:");
                scanf("%d", &val);
                printf("At row = ");
                scanf("%d", &row);
                printf("At column = ");
                scanf("%d", &col);
                insert(val, row, col);
                break;
            case 4:
                printf("Enter row of element to delete:");
                scanf("%d", &row);
                printf("Enter column of element to delete:");
                scanf("%d", &col);
                delete(row, col);
                break;
            case 10:
                return 0;
            default:;
        }
    }
    return 0;
}
