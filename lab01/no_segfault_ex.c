#include <stdio.h>
int main() {
    int a[5] = {1, 2, 3, 4, 5}; // int array
    unsigned total = 0; 
    for (int j = 0; j < sizeof(a); j++) { // sizeof(a) may depends on the system? a is a pointer?
        total += a[j];
    }
    printf("sum of array is %d\n", total);
}