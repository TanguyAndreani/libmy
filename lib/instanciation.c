#include <wchar.h>
#include <string.h>
#include <stdlib.h>

#include "../include/my_string.h"

static my_string *my_string_init(my_string *s, int buffer_size) {
  if (!s)
    return (NULL);

  s->size = 0;
  s->buffer_size = buffer_size;

  s->unicode = malloc(sizeof(wchar_t) * buffer_size);
  if (!s->unicode)
    return (NULL);
  wmemset(s->unicode, 0, buffer_size);

  return (s);
}

my_string *my_string_create(wchar_t *unicode) {
  my_string *s = malloc(sizeof(my_string));
  if (!s)
    return (NULL);

  int length = wcslen(unicode);

  if (!my_string_init(s, length + 1)) {
    free(s);
    return (NULL);
  }

  wcscpy(s->unicode, unicode);

  s->size = length;

  return (s);
}

void my_string_destroy(my_string *s) {
  free(s->unicode);
  memset(s, 0, sizeof(my_string));
  free(s);
}
