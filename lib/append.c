#include <wchar.h>
#include <string.h>
#include <stdlib.h>

#include "../include/my_string.h"

static long max_long(long a, long b) {
  return (a > b) ? a : b;
}

int my_string_append(my_string *dest, wchar_t *src, long n) {
  long src_len = wcslen(src);
  long total_size = dest->size + max_long(src_len, n);

  if (dest->buffer_size < total_size + 1) {
    dest->unicode = realloc(dest->unicode, (total_size + 1) * sizeof(wchar_t));
    if (!dest->unicode)
      return -1;
    dest->buffer_size = total_size + 1;
  }

  (void)wcsncpy(dest->unicode + dest->size, src, n + 1);
  dest->size = total_size;

  return 0;
}
