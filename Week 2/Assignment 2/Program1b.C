#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    for(int i = 0; i < 10; i++){
        printf("Iteration %d\n", i);
        if (i==7)
        {
            printf("Exiting at iteration 7\n");
            exit(0);
        }
    }
    return 1;
}