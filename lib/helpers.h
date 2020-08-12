#ifndef PRIVATE_H
#define PRIVATE_H

long my_string_max_long(long a, long b);

void *my_malloc_helper(void *tmp, char *file, int line);

#ifndef NDEBUG
#define my_malloc(size) \
  my_malloc_helper(malloc(size), __FILE__, __LINE__)

#define my_realloc(ptr, size) \
  my_malloc_helper(realloc(ptr, size), __FILE__, __LINE__)
#else
#define my_malloc(size) malloc(size)
#define my_realloc(ptr, size) realloc(ptr, size)
#endif

#endif
