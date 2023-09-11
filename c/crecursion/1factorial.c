// SECTION TAIL RECURSION

#include <stdio.h>

int factorialTail(int n)
{
    // Base case
    if (n == 1 || n ==0) {
        return 1;
    } else {
        // tail recursive call
        return n * factorialTail(n-1);
    }
}

int main() {
    int n = 5;

    int fact1 = factorialTail(n);
    printf("Recursive Factorial of %d: %d \n", n, fact1);

    return 0;
}

