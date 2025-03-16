
#include <assert.h>
#include <stdio.h>

#include "alloc.h"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  // should coalesce
  void *p1 = malloc(2000);
  void *p2 = malloc(1000);
  void *p3 = malloc(1000);
  printf("allocated\n");
  alloc__print();
  free(p1);
  printf("freed p1\n");
  alloc__print();
  free(p3);
  printf("freed p3\n");
  alloc__print();
  free(p2);
  printf("freed p2\n");
  alloc__print();
}
