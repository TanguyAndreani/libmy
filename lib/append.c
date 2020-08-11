#include <wchar.h>
#include <string.h>
#include <stdlib.h>

#include "../include/my_string.h"

static long max_long(long a, long b) {
  return (a > b) ? a : b;
}

static int my_string_append_unicode(my_string *dest, wchar_t *src, long n) {
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

static int my_string_append_ascii(my_string *dest, char *src, long n) {
  long src_len = strlen(src);
  long total_size = dest->size + max_long(src_len, n);

  if (dest->buffer_size < total_size + 1) {
    dest->unicode = realloc(dest->ascii, total_size + 1);
    if (!dest->ascii)
      return -1;
    dest->buffer_size = total_size + 1;
  }

  (void)strncpy(dest->ascii + dest->size, src, n + 1);
  dest->size = total_size;

  return 0;
}

int my_string_append(my_string *dest, void *src, long n) {
  if (dest->type == MY_STRING_UNICODE) {
    return my_string_append_unicode(dest, src, n);
  } else if (dest->type == MY_STRING_ASCII) {
    return my_string_append_ascii(dest, src, n);
  }

  return (-1);
}
