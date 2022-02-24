#ifndef LISTS_H
#define LISTS_H
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
void left(int *line, size_t size);
void right(int *line, size_t size);


#endif /* LISTS_H */
