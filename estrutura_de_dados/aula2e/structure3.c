#include <stdio.h>
#include <stdlib.h>

typedef struct aux
{
    int cpf;
    int age;
    struct aux *partner;
} person;

void print_couple_cpf(person p)
{
    if (p.partner != NULL)
    {
        printf("CPFs: %i x %i\n", p.cpf, p.partner->cpf);
    }
}

int main()
{
    person person1;
    person person2;

    person1.cpf = 23000;
    person1.age = 27;
    person1.partner = &person2;

    person2.cpf = 47000;
    person2.age = 25;
    person2.partner = &person1;

    print_couple_cpf(person1);

    return 0;
}