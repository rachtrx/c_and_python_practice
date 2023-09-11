// SECTION indirect recursion

#include <stdio.h>

void functionA(int n);
void functionB(int n);

void functionA(int n) {
    if (n < 1) {
        return;
    }
    printf("%d ", n);
    n = n -1;

    // indirect recursive call to functionB
    functionB(n);
}

void functionB(int n) {
    if (n<2) {
        return;
    }

    printf("%d ", n);
    n = n/2;

    // indirect recursive call to function A
    functionA(n);
}

int main() {
    functionB(20);

    printf("\n");

    return 0;
}