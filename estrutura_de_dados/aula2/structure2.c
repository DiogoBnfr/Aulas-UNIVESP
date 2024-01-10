#include <stdio.h>
#include <malloc.h>
#define maxHeight 225

typedef struct
{
    int weight;
    int height;
} person;

int main()
{
    person *person1 = (person *)malloc(sizeof(person));
    person1->weight = 80;
    person1->height = 176;

    printf("Weight: %d\nHeight: %d", person1->weight, person1->height);
    return 0;
}