#include <stdio.h>
#include "line.h"

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "使い方: %s ファイル名1 ファイル名2\n", argv[0]);
        return 1;
    }

    Line l1;
    Line l2;

    init_line(&l1, argv[1], 32);
    init_line(&l2, argv[2], 32);

    char *line1;
    while ((line1 = get_line(&l1)) != NULL) {
        printf("%s\n", line1);
    }

    char *line2;
    while ((line2 = get_line(&l2)) != NULL) {
        printf("%s\n", line2);
    }

    term_line(&l1);
    term_line(&l2);

    return 0;
}
