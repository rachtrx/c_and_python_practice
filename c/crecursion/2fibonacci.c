// SECTION TREE RECURSION

#include <stdio.h>

int fibonacci(int n) {
    // base case
    // fibonacci of 0 and 1 is the number itself
    if (n <= 1) {
        return n;
    } else {
        // tree recursive calls
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    // function call
    int n = fibonacci(3);
    printf("%d \n", n);

    return 0;
}