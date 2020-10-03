/*
    @author Roman Korostenskyi
    @date 08.10.2018

    Simple factorial algorithm based on loop
*/
int factorial_loop(int n) {
    int output = 1;

    for (int i = n; i >= 1; i--) {
        output *= i;
    }

    return output;
}