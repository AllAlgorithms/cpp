
// Algorith in C++ for Pascal's Triangle of n Lines
#include <stdio.h>
int binomialCoeff(int n, int k);

// Function to print first n lines of Pascal's Triangle
void printPascal(int n)
{
    for (int line = 0; line < n; line++)
    {
        for (int i = 0; i <= line; i++)
            printf("%d ",
                    binomialCoeff(line, i));
        printf("\n");
    }
}


int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
    k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}


int main()
{
    int n = 7;
    printPascal(n);
    return 0;
}
