#include <iostream>

#define N 3
using namespace std;


bool isMagicSquare(int mat[][N])
{

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum = sum + mat[i][i];


    for (int i = 0; i < N; i++) {

        int rowSum = 0;
        for (int j = 0; j < N; j++)
            rowSum += mat[i][j];


        if (rowSum != sum)
            return false;
    }


    for (int i = 0; i < N; i++) {

        int colSum = 0;
        for (int j = 0; j < N; j++)
            colSum += mat[j][i];


        if (sum != colSum)
        return false;
    }

    return true;
}


int main()
{
    int mat[3][N] ,i,j;
    
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        cin>>mat[i][j];
    }

    if (isMagicSquare(mat))
        cout << "Magic Square";
    else
        cout << "Not a magic Square";

    return 0;
}
