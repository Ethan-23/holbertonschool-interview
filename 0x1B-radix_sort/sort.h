#ifndef SORT_H
#define SORT_H

#include <stdio.h>

void radix_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void sort(int *array, int size, int exp);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
