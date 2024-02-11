#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {

    /*// 1.
    char operator = *argv[3];
    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);

    if (operator == '+') {
        int sum = arg1 + arg2;
        printf("%d", sum);
    } else if (operator == '-') {
        int diff = arg1 - arg2;
        printf("%d", diff);
    } else if (operator == 'x') {
        int prod = arg1 * arg2;
        printf("%d", prod);
    } else if (operator == '/') {
        int quot = arg1 / arg2;
        printf("%d", quot);
    } else if (operator == '^') {
        int pow = arg1;
        for (int i = 1; i < arg2; i++) {
            pow *= arg1;
        }
        printf("%d", pow);
    }
    else {
        printf("Invalid operator");
    }*/

    // 2.
    FILE *fp = fopen(argv[1], "r");
    FILE *fpout = fopen(argv[2], "w");

//    char in_path[100];
//    char out_path[100];
//
//    strcpy(in_path, argv[1]);
//    strcpy(out_path, argv[2]);
//
//    fp = fopen(in_path, "r");
//    fpout = fopen(out_path, "w");

//    printf("%s\n", in_path);

    int i = 0;
    char c;
    while (!feof(fp)) {
        i++;
        fscanf(fp, " %s ", &c);
        printf(" %c ", c);
        printf("%d\n", i);
    }

    fclose(fp);
    fclose(fpout);

    return 0;
}
