
#ifndef ALLOC_H
#define ALLOC_H
#include <stdlib.h>

void *alloc__malloc(size_t size);
void alloc__free(void *addr);
void alloc__print();

#endif
