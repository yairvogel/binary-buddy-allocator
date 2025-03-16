# Memory Allocator Implementation

This project implements a simple memory allocator in C, inspired by concepts from the book "Operating Systems: Three Easy Pieces" by Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau.

## Overview

This implementation provides a basic memory allocation system with the following features:

- Custom `alloc__malloc()` function for memory allocation
- Custom `alloc__free()` function for releasing memory
- Memory visualization with `alloc__print()`
- Memory splitting and coalescing

## Background

This project was created while studying memory management concepts from [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/), specifically the chapters on memory management and allocation.

## Building and Running

Use the provided Makefile to build the project:

```bash
make
```

Run the program:

```bash
./build/program
```

## Implementation Details

The allocator uses a simple free-list approach with a first-fit allocation strategy. Memory blocks are represented by nodes that track size and occupancy status.

## License

This is an educational project and is provided as-is.
