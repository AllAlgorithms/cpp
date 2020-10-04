//Funcion factorial
unsigned long int factorial (unsigned long int valor)
{
    if (valor<=1)
        return valor=1;
    else
        return valor=valor*factorial(valor-1);
}

/*///////////////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////////////*/

//Funcion binomial(requiere la funcion factorial)
float numero_binomio (unsigned long int arriba,unsigned long int abajo)
{
    float respuesta;
    respuesta = factorial(arriba) / (factorial(abajo) * factorial(arriba-abajo));
    return respuesta;
}
