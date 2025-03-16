
#include <assert.h>
#include <stdio.h>

#include "alloc.h"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  // should coalesce
  void *p1 = alloc__malloc(2000);
  void *p2 = alloc__malloc(1000);
  void *p3 = alloc__malloc(1000);
  printf("allocated\n");
  alloc__print();
  alloc__free(p1);
  printf("freed p1\n");
  alloc__print();
  alloc__free(p3);
  printf("freed p3\n");
  alloc__print();
  alloc__free(p2);
  printf("freed p2\n");
  alloc__print();
}
