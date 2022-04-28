#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <stdio.h>

void print_array(int *array, int start, int end);
int advanced_binary(int *array, size_t size, int value);
int find_value(int *array, int start, int end, int value, size_t size);

#endif
