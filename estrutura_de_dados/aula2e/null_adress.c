#include <stdio.h>
#include <stdlib.h>

typedef struct aux
{
    int cpf;
    int age;
    struct aux *partner;
} person;

// void get_old(person p) this modifies a copy of person
void get_old(person *p)
{
    p->age++;
}

// void get_partner_old(person p) this modifies the partner
// but need a copy of person to do that
void get_partner_old(person *p)
{
    p->partner->age++;
}

int main()
{
    person person1;
    person person2;
    person single;

    person1.cpf = 23000;
    person1.age = 27;
    person1.partner = &person2;

    person2.cpf = 47000;
    person2.age = 25;
    person2.partner = &person1;

    single.cpf = 11000;
    single.age = 17;
    single.partner = NULL;

    // get_old(person1); this pass a copy of person
    get_old(&person1);

    // get_partner_old(person1); this too
    get_partner_old(&person1);

    printf("Couple age: %i x %i", person1.age, person2.age);

    return 0;
}