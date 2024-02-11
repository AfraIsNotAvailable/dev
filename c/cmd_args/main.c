#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 1. Implementati un calculator simplu care lucreaza cu 3 argumente din
    // linia de comanda: doi operanzi si un operator. Operatorul poate fi +, -,
    // *, /, ^ (ridicare la putere) si operanzii sunt numere zecimale. Sa se
    // afiseze rezultatul operatiei. Se trateaza situatiile speciale. Exemplu de
    // apel din linia de comanda:

    // ./main 2 + 3
    printf("%d %s", argc, &argv[1]);

    // if (*argv[3] == '+') {
    //     printf("%d %d", argv[1], argv[2]);
    // }

    return 0;
}
