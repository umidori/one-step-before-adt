#include "line.h"
#include <stdio.h>
#include <stdlib.h>

void init_line(Line *l, char *fname, int cap)
{
    if ((l->fp = fopen(fname, "r")) == NULL) {
        perror("fopen");
        exit(1);
    }
    l->cap = cap;
    l->line = (char *)malloc(l->cap);
}

char *get_line(Line *l)
{
    int c;
    int n = 0;
    char *new_line;
    while ((c = fgetc(l->fp)) != EOF && c != '\n') {
        if (n >= l->cap - 1) {
            l->cap = l->cap * 2;
            new_line = (char *)realloc(l->line, l->cap);
            if (new_line == NULL) {
                perror("realloc");
                free(l->line);
                exit(1);
            }
            l->line = new_line;
        }
        l->line[n++] = c;
    }
    if (c == EOF && n == 0) {
        return NULL;
    }
    l->line[n] = '\0';
    return l->line;
}

void term_line(Line *l)
{
    free(l->line);
    fclose(l->fp);
}
