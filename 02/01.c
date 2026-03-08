// determine ranges of char, short, int, and long variables
    // include both signed and unsigned 
    // do by printing from standard headers and direct computation

#include <stdio.h>
#include <limits.h>

int main() {
    printf("from standard headers:\n");
    printf("----------------------\n");
    printf("unsigned char: %d to %d\n", 0, UCHAR_MAX);
    printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("-\n");
    printf("unsigned short: %d to %d\n", 0, USHRT_MAX);
    printf("signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("-\n");
    printf("unsigned int: %d to %u\n", 0, UINT_MAX);
    printf("signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("-\n");
    printf("unsigned long: %d to %lu\n", 0, ULONG_MAX);
    printf("signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    
    printf("\n\n");

    // computed ranges
    unsigned char ucharmax = (int)-1;
    int scharmax = ucharmax/2;
    int scharmin = -scharmax-1;
    unsigned short shrt = -1;
    int ushrtmax = (int)shrt;
    int sshrtmin = -(ushrtmax/2);
    int sshrtmax = ushrtmax/2 - 1;
    unsigned int uintmax = (unsigned int)-1;
    int sintmax = (int)(uintmax / 2);
    int sintmin = -sintmax - 1;
    unsigned long ulongmax = (unsigned long)-1;
    long slongmax = (long)(ulongmax / 2);
    long slongmin = -slongmax - 1;

    printf("from \"direct computation\":\n");
    printf("----------------------------\n");
    printf("unsigned char: %d to %d\n", 0, ucharmax);
    printf("signed char: %d to %d\n", scharmin, scharmax);
    printf("-\n");
    printf("unsigned short: %d to %d\n", 0, ushrtmax);
    printf("signed short: %d to %d\n", sshrtmin, sshrtmax);
    printf("-\n");
    printf("unsigned int: %d to %u\n", 0, uintmax);
    printf("signed int: %d to %d\n", sintmin, sintmax);
    printf("-\n");
    printf("unsigned long: %d to %lu\n", 0, ulongmax);
    printf("signed long: %ld to %ld\n", slongmin, slongmax);
    
}
