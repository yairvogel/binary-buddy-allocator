
#ifndef ALLOC_H
#define ALLOC_H
#include <stdlib.h>

#define malloc(size) alloc__malloc(size);
#define free(addr) alloc__free(addr);

void *alloc__malloc(size_t size);
void alloc__free(void *addr);
void alloc__print();

#endif
