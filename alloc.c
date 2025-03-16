
#include "alloc.h"

#include <stdio.h>

// 1 << 12 * 8 bytes
#define MEM32K 4096

typedef struct __node_t {
  size_t size;
  char occupied;
} node_t;

static char mem[MEM32K];
static char initialized = 0;

void init() {
  if (!initialized) {
    initialized = 1;
    node_t *node = (node_t *)mem;
    node->size = MEM32K;
    node->occupied = 0;
  }
}

char eligible(node_t *node, size_t size) {
  return (!node->occupied) && (node->size >= (size + sizeof(node_t)));
}

node_t *split_node(node_t *node) {
  size_t new_size = node->size >> 1;
  node->size = new_size;
  char *addr = (char *)node;
  addr += new_size;
  node_t *new_node = (node_t *)addr;
  new_node->size = new_size;
  new_node->occupied = 0;
  return node;
}

void *alloc__malloc(size_t size) {
  init();
  char *addr = mem;
  while (addr < mem + MEM32K && !eligible((node_t *)addr, size)) {
    // if in range, we're guaranteed to find an initialized node
    addr += ((node_t *)addr)->size;
  }

  if (addr >= mem + MEM32K) {
    // no eligible case
    return NULL;
  }

  node_t *node = (node_t *)addr;
  while (node->size >> 1 > (size + sizeof(node_t))) {
    split_node(node);
  }

  node->occupied = 1;

  return node;
}

void alloc__free(void *addr) {
  if (!initialized) {
    fprintf(stderr, "cannot free uninitialized memory\n");
    exit(1);
  }

  (void)addr;
  return;
}

void alloc__print() {
  init();
  for (char *node = mem; node < mem + MEM32K; node += ((node_t *)node)->size) {
    node_t *n = (node_t *)node;
    printf("node at %p: { size: %ld, occupied: %d }\n", n, n->size,
           n->occupied);
  }
}
