#include "mlnode.h"

int main() {
    MLNODE *head = NULL;
    int c, val, row, col;
    while (1) {
        printf("1. Initialize Sparse Matrix.\n");
        printf("2. Display Sparse Matrix.\n");
        printf("3. Insert element in Sparse Matrix.\n");
        printf("4. Delete element in Sparse Matrix.\n");
        printf("5. Swap the i-th row and j-th row of the Sparse Matrix.\n");
        printf("10. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter number of rows to insert:");
                scanf("%d", &row);
                printf("Enter number of columns to insert:");
                scanf("%d", &col);
                head = init(row, col);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter value to insert:");
                scanf("%d", &val);
                printf("At row = ");
                scanf("%d", &row);
                printf("At column = ");
                scanf("%d", &col);
                head = insertion(head, val, row - 1, col - 1);
                break;
            case 4:
                printf("Enter value to delete:");
                scanf("%d", &val);
                head = deletion(head, val);
                break;
            case 5:
                printf("Enter row 1 to swap:");
                scanf("%d", &row);
                printf("Enter row 2 to swap:");
                scanf("%d", &col);
                head = swapRows(head, row - 1, col - 1);
                break;
            case 10:
                return 0;
            default:;
        }
    }
    return 0;
}
