// rewrite bin search from 3.3 using only one test inside loop and measure difference in run time

#include <stdio.h>

int binsearch (int x, int v[], int n) {
    int lo=0, hi=n-1, mid;

    while (lo+1<hi) {
        int mid = (lo+hi)/2;
        if (x<v[mid]) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    
    if (v[lo] == x) {
        return lo;
    } 
    return -1;
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    printf("%d should be 3\n", binsearch(4, v, 5));
}