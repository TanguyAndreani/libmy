#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "../../include/my_string.h"

int my_string_append(my_string *dest, wchar_t *src, long n) {
  assert(dest);
  assert(src);
  assert(n >= 0);

  long src_len = wcslen(src);

  if (!n || n > src_len)
    n = src_len;

  long total_size = dest->size + n;

  if (dest->buffer_size < total_size + 1) {
    dest->unicode = realloc(dest->unicode, (total_size + 1) * sizeof(wchar_t));
    if (!dest->unicode)
      return -1;
    dest->buffer_size = total_size + 1;
  }

  for (long i = 0; i < n; i++)
    dest->unicode[dest->size + i] = src[i];

  dest->size = total_size;

  return 0;
}

int my_string_append_wr(my_string *dest, my_string *src, long n) {
  return my_string_append(dest, src->unicode, n);
}