/* A program to demonstrate three places that you
can declare a scalar variable: as a global (i),
as a local (j) or as a procedure parameter (argc). */
#include <stdio.h>
#include <stdlib.h>
int i;
int main(int argc, char **argv)
{
    int j;
    /* Copy argc to j to i and print i */
    j = argc;
    i = j;
    printf("Argc: %d\n", i);
    /* Print the size of a long. */
    j = sizeof(long);
    printf("Sizeof(long): %d\n", j);
    /* Print the size of a pointer. */
    j = sizeof(int *);
    printf("Sizeof(int *): %d\n", j);
    return 0;
}