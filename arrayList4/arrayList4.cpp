#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>

struct Tname
{
    char Tname[15];
};

struct Tnumber
{
    char Tnumber[7];
};

struct elem {
    struct Tnumber* number;
    struct elem* next;
    struct elem* prev;
};

struct array {
    struct Tnumber* number;
    struct array* next;
};

int size(struct elem* curr)
{
    if ((curr->number->Tnumber[6] >= '0') && (curr->number->Tnumber[6] <= '9'))
        return 7; else
        return 3;
}

void write(struct array* first) {
    struct array* curr = first;
    while (curr->next != NULL)
    {
        curr = curr->next;
        for (int i=0; i<7; i++)
        printf("%c", curr->number->Tnumber[i]);
                printf("\n");
    }
}

int big(struct array* elem1, struct elem* elem2)
{
    for (int i = 0; i < 7; i++)
    {
        if (elem1->number->Tnumber[i] > elem2->number->Tnumber[i]) return 1;
        if (elem1->number->Tnumber[i] < elem2->number->Tnumber[i]) return 0;
    }
    return 1;
}

int main()
{
    struct elem* current = (struct elem*)malloc(sizeof(struct elem));
    struct elem* head = current;
    current->next = NULL;
    current->prev = NULL;

    printf("Enter size of the book: ");
    int kol;
    char inter;
    scanf("%d%c", &kol, &inter);

    for (int i = 0; i < kol; i++)
    {

        printf("%d) number: ", i);
        struct Tnumber* number = (struct Tnumber*)malloc(sizeof(struct elem));
        int j = -1;
        while (number->Tnumber[j] != '\12')
        {
            j++;
            scanf("%c", &number->Tnumber[j]);
        }
        number->Tnumber[j] = '\0';

        current->next = (struct elem*)malloc(sizeof(struct elem));
        current->next->prev = current;
        current = current->next;
        current->number = number;
        current->next = NULL;

    }

    struct array* curr = (struct array*)malloc(sizeof(struct elem));
    struct array* first = curr;
    curr->next = NULL;

    do
    {
        if (size(current) == 7)
        {
            curr = first;
            while ((curr->next != NULL) && (big(curr->next, current)==0))
                curr = curr->next;

            struct array* elem = (struct array*)malloc(sizeof(struct elem));
            elem->number = current->number;
            elem->next = curr->next;
            curr->next = elem;
        }

        current = current->prev;

    } while (current->prev != NULL);

    write(first);
}