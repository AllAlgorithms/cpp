
void Gauss_Jordan (double m[][MAX],int fila,int columna)
{
    int i,j,t,k,l;
    double divisores[MAX];
    int fila_pivote=0;

    for (t=0; t<fila; t++)
    {

        //Division unica
        if(m[t][t]!=1)
            for (l=columna-1; l>=t; l--)
            {
                m[t][l]=m[t][l]/m[t][t];
            }

        //Divisores
         for (k=0; k<fila; k++)
            divisores [k] = 1.0*m[k][t]/m[t][t];

        for (i=0; i<fila_pivote; i++)
            for (j=0; j<columna; j++)
                m[i][j] = m[i][j] - m[t][j]*divisores[i];

        for (i=1+fila_pivote; i<fila; i++)
            for (j=0; j<columna; j++)
                m[i][j] = m[i][j] - m[t][j]*divisores[i];

        fila_pivote++;
    }
}
