#include <stdio.h>

struct entry
{
    char fname[20];
    char lname[20];
    char phone[15];
};

#define MAX 4

int main(void)
{
    struct entry list[MAX];
    struct entry *p_entry;
    int i;

    /* Loop to input data for four people */
    for (p_entry = list, i = 0; i < MAX; p_entry++, i++)
    {
        printf("\nEnter first name: ");
        scanf("%19s", p_entry->fname);
        printf("Enter last name: ");
        scanf("%19s", p_entry->lname);
        printf("Enter phone in 123-4567 format: ");
        scanf("%14s", p_entry->phone);
    }

    printf("\n\n");

    /* Loop to display data */  
    for (p_entry = list, i = 0; i < MAX; p_entry++, i++)
    {
        printf("Name: %s %s", p_entry->fname, p_entry->lname);
        printf("\t\tPhone: %s\n", p_entry->phone);
    }

    return 0;
}
