
#include <assert.h>

#include "alloc.h"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  alloc__malloc(2000);
  alloc__malloc(1000);
  alloc__print();
}
