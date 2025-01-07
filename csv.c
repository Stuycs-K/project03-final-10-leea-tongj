#include "headers.h"

struct table read_csv(char PATH[256]) {
    char s[256];
    FILE *csv = fopen(PATH, "r");
    fgets(s, 255, csv);
    char c[256];
    sscanf(s,"%[^\n]",c);
    char *curr = c;
    int rows = 0;
    while (curr) {
        strsep(&curr, ",");
        rows++;
    }
}