#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    printf("Enter the number 5: ");
    scanf("%d", &num);
    if(num == 5){
        printf("Equal\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Not Equal\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}