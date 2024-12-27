# Shell Sort Performance Comparison

This project compares the performance of the Shell Sort algorithm with and without parallelism in a worst-case scenario using OpenMP. It measures the time taken to sort an array of integers in reverse order using both implementations.

## Features

- **Sequential Shell Sort**: A standard implementation of the Shell Sort algorithm.
- **Parallel Shell Sort**: A Shell Sort implementation optimized with OpenMP for parallel processing.
- Performance measurements using C++ `<chrono>` library.

## Requirements

To compile and run this program, you need:

- A C++ compiler with OpenMP support (e.g., GCC or Clang).
- A modern C++ standard (C++11 or later).

## Compilation

To compile the program, use the following command in a terminal or command prompt:

```bash
g++ -o shell_sort project.cpp -fopenmp -std=c++11
