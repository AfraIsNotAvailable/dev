#include <stdio.h>

void driver_function2() {
    char c;
    float f;
    float s = 0;
    float d = 0;
    int i = 0;
    while (i < 3) {
        scanf(" %c %f kg", &c, &f);
        if (c == 'S') {
            s += f;
        } else if (c == 'D') {
            d += f;
        }
        i++;
    }

    if (s > d) {
        printf("S");
    } else if (d > s) {
        printf("D");
    } else {
        printf("Echilibrat");
    }
}

int main(int, char **) {
    driver_function2();

    return 0;
}