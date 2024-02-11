#include <stdio.h>
#include <stdlib.h>

struct Camion {
    char inmatriculare[30];
    int an;
    char culoare[50];
    char marca[50];
    float km;
};

int main(int, char**){
    FILE *fp = fopen("./in.txt", "r");

    int n;
    fscanf(fp, "%d", &n);
    struct Camion camioane[n];
    for (int i = 0; i < n; i++) {
        fscanf(fp, " %s,%d,%s,%s,%f", camioane[i].inmatriculare, &camioane[i].an, camioane[i].culoare, camioane[i].marca, &camioane[i].km);
    }

    printf("%d", camioane[0].an);

    return 0;
}
