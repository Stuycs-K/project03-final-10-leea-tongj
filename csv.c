#include "headers.h"

void read_csv(char *PATH) {
    char s[256];
    FILE *csv = fopen(PATH, "r");
    fgets(s, 255, csv);
    char *curr = s;
    int cols = 0;
    while (curr) {
        strsep(&curr, ",");
        cols++;
    }
    int rows = 1;
    while (fgets(s, 255, csv)) {
        rows++;
    }
    printf("rows: %d columns: %d\n", rows, cols);
}