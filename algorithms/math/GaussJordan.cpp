void GaussJordan(double m[][MAX], int row, int column)
{
    int i, j, t, k, l;
    double divisors[MAX];
    int row_pivot=0;

    for (t=0; t<row; t++)
    {
        //Single division
        if(m[t][t]!=1) {
            for (l=column-1; l>=t; l--)
            {
                m[t][l] = m[t][l]/m[t][t];
            }
        }

        //Divisors
        for (k=0; k<row; k++)
            divisors[k] = 1.0*m[k][t]/m[t][t];

        for (i=0; i<row_pivot; i++)
            for (j=0; j<column; j++)
                m[i][j] = m[i][j] - m[t][j]*divisors[i];

        for (i=1+row_pivot; i<row; i++)
            for (j=0; j<column; j++)
                m[i][j] = m[i][j] - m[t][j]*divisors[i];

        row_pivot++;
    }
}