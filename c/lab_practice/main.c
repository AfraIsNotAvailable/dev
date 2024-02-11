#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char nume[26];
    char prenume[26];
    int varsta; // 1 - 100
    char *adresa;
    float media_generala;
} Student;

int main(int, char **) {
    int n;

    printf("nr de studenti: ");
    scanf("%d", &n);

    Student * catalog = (Student *)malloc(n * sizeof(Student));

    for (int i=0; i < n; i++) {
        scanf("%s", catalog[i].nume);
    }

    for (int i = 0; i < n; i++) {
        printf("Salut %s\n", catalog[i].nume);
    }

    return 0;
}
