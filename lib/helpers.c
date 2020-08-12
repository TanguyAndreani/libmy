#include <stdlib.h>
#include <stdio.h>

long my_string_max_long(long a, long b) {
  return (a > b) ? a : b;
}

void *my_malloc_helper(void *tmp, char *file, int line) {
  if (!tmp) { \
    fprintf(stderr, "%s:%d memory allocation failed.\n", file, line); \
    fflush(stderr);
    return NULL;
  }
  return tmp;
}
