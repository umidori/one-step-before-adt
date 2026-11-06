#ifndef __GET_LINE_H__
#define __GET_LINE_H__
#include <stdio.h>

typedef struct {
   FILE *fp;
   char *line;
   int cap;
} Line;

void init_line(Line *line, char *fname, int cap);
char *get_line(Line *line);
void term_line(Line *line);

#endif
