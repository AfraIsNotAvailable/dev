#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// in1: 10:40:10-11:20:10 10:30:05-11:00:00 -- 00:19:50
// in2: 14:23:00-15:34:21 08:10:30-16:12:40 -- 01:11:21
// in3: 08:10:00-09:30:00 10:40:00-11:20:00 -- No overlap

void time_parse(char *input, int **output) {
    // initial format: "10:40:10-11:20:10"
    char *token = strtok(input, "-:");
    int *time = malloc(6 * sizeof(int));
    int i = 0;
    while (token != NULL) {
        sscanf(token, "%d", &time[i]);
        token = strtok(NULL, "-:");
        i++;
    }
    i = 0;
    while (i < 6) {
        (*output)[i] = time[i];
        i++;
    }
    free(time);
}

void interval(int *time, int *start, int *end) {
    *start = time[0] * 3600 + time[1] * 60 + time[2];
    *end = time[3] * 3600 + time[4] * 60 + time[5];
}

// Problema 1
int driver_function() {
    char input[100];
    char input2[100];
    int *output = malloc(6 * sizeof(int));
    int start;
    int end;
    int start2;
    int end2;

    scanf("%99s", input);
    scanf("%99s", input2);
    time_parse(input, &output);
    interval(output, &start, &end);
    time_parse(input2, &output);
    interval(output, &start2, &end2);
    // printf("%d %d -- %d %d\n", start, end, start2, end2);

    if (start2 > end) {
        printf("No overlap");
        free(output);
        return 0;
    }
    if (end2 < start) {
        printf("No overlap");
        free(output);
        return 0;
    }

    // Choosing the extremes
    if (start2 < start) {
        start2 = start;
    }
    if (end2 > end) {
        end2 = end;
    }

    // Calculating the values separately
    int hour = (end2 - start2) / 3600;
    int minute = (end2 - start2) / 60;
    int second = (end2 - start2) % 60;

    // Adjusting the values to the correct format
    if (hour > 60) {
        hour = hour % 60;
    }
    if (minute > 60) {
        minute = minute % 60;
    }
    if (second > 60) {
        second = second % 60;
    }

    printf("%02d:%02d:%02d", hour, minute, second);

    free(output);
    return 0;
}

int main(int, char **) {
    driver_function();

    return 0;
}