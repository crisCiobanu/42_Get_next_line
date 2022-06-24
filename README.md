# Ecole 42 get_next_line Project
> The aim of this project is to code a function that returns a line read from a file descriptor.

## Goals
- calling the function in a loop will allow to read the text available on the file descriptor one line at a time until the end of it.
- the function should perform well when it reads from a file and when it reads from the standart input.
- if an error has occured or the end of file was reached the function should return NULL.

## Requirements

- you should have installed on your machine a **C** compiler like `gcc` or `clang` and the standard **C** libraries.

## Usage

- include th header of the function in your code:
```C
#include "get_next_line.h"
```
- at compilation add the desired BUFFER_SIZE or the default 42 size will be used.
```shell
-D BUFFER_SIZE=<size>
```

## Testing

- There are few tests in the `main` function in `get_next_line.c` file , uncommenting the main and compiling the project will launch the tests.
- A third party tester is available on [GNL Tester](https://github.com/Tripouille/gnlTester)

## About Ecole 42 Mulhouse

> Ecole 42 Mulhouse a part of **42 Network** that includes 44 campuses in 26 countries, is a software-engineering school that provides a different way of teaching programmig.

### The 42 Method:
- Learnig to Learn
- Learning together : Peer-to-Peer
- Learning throw practice
