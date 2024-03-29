#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "../../include/my_string.h"

#include "../helpers.h"

static my_string *my_string_init(my_string *s, long buffer_size) {
  s->size = 0;
  s->buffer_size = buffer_size;

  s->unicode = my_malloc(sizeof(wchar_t) * buffer_size);
  if (!s->unicode)
    return (NULL);

  (void)wmemset(s->unicode, 0, buffer_size);

  return (s);
}

my_string *my_string_create(wchar_t *unicode, long n) {
  assert(unicode);
  assert(n >= 0);

  my_string *s = my_malloc(sizeof(my_string));
  if (!s)
    return (NULL);

  if (!n)
    n = wcslen(unicode);

  if (!my_string_init(s, my_string_max_long(n + 1, 50))) {
    free(s);
    return (NULL);
  }

  for (long i = 0; i < n; i++)
    s->unicode[i] = unicode[i];

  s->size = n;

  return (s);
}

void my_string_destroy(my_string *s) {
  if (s) {
    free(s->unicode);
    memset(s, 0, sizeof(my_string));
    free(s);
  }
}
