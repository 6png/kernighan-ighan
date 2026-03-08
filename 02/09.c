// use two's complement to rewrite bitcount(x) 
    // rets num of 1s in binary of x

int bitcount(unsigned x) {
    int i;
    for (i=0; x!=0; x&=(x-1)) {
        i++;
    }
    return i;
}

int main() {
    printf("%d", bitcount(0xFF));
}