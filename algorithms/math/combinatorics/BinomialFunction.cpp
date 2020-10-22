//factorial function
unsigned long int factorial (unsigned long int value)
{
    if (value<=1)
        return 1;
    else
        return value*factorial(value-1);
}

/*///////////////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////////////*/

//Binomial function(requires the factorial function): nCr
unsigned long int binomial_number(unsigned long int n, unsigned long int r)
{
    return factorial(n) / (factorial(r) * factorial(n-r));
}
