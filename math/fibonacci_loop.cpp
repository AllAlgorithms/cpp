/*
    @author Roman Korostenskyi
    @date 08.10.2018

    Simple algorithm based on loop for calculating Fibonacci numbers
*/

unsigned long fibonacci(int n) {
    if (n <= 1){
        return n;
    }

    long previous = 0;
    long current = 1;

    for (long i = 2; i <= n; i++){
        long new_current = previous + current;
        previous = current;
        current = new_current;
    }

    return current;
}
