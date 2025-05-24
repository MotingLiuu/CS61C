#include <stdio.h>
int main() {
    int a[5] = {1, 2, 3, 4, 5}; // int array
    unsigned total = 0; 
    for (int j = 0; j < sizeof(a); j++) { // a is a real array, not a pointer. so sizeof(a) is 20.
        total += a[j];
    }
    printf("size of a is %d\n", sizeof(a));
    printf("sum of array is %d\n", total);
}