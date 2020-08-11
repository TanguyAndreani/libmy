#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/my_string.h"

#include "private.h"

static my_string *my_string_init(my_string *s, long buffer_size) {
  s->size = 0;
  s->buffer_size = buffer_size;

  s->unicode = malloc(sizeof(wchar_t) * buffer_size);
  if (!s->unicode)
    return (NULL);

  (void)wmemset(s->unicode, 0, buffer_size);

  return (s);
}

my_string *my_string_create(wchar_t *unicode) {
  assert(unicode);

  my_string *s = malloc(sizeof(my_string));
  if (!s)
    return (NULL);

  int length = wcslen(unicode);

  if (!my_string_init(s, my_string_max_long(length + 1, 50))) {
    free(s);
    return (NULL);
  }

  wcscpy(s->unicode, unicode);

  s->size = length;

  return (s);
}

void my_string_destroy(my_string *s) {
  if (s) {
    free(s->unicode);
    memset(s, 0, sizeof(my_string));
    free(s);
  }
}
