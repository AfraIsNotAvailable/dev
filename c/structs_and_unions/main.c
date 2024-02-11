#include <stdio.h>
#include <string.h>

struct Address {
    char street[50];
    char city[50];
    int zipCode;
};

struct Student {
    char name[30];
    int age;
    float grade;
    struct Address address;
};

union Data {
    int integer;
    float floating_point;
    char character;
};

int main(int, char **) {
    struct Student s;

    strcpy(s.name, "Serban Afrasinei");

    printf("Hello there %s\n", s.name);

    union Data data;
    data.character = 'a';
    data.integer = 23;

    printf("%c", data.character);

    return 0;
}
