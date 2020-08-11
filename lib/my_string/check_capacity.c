#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "../../include/my_string.h"

int my_string_check_capacity(my_string *s, long new_size) {
  assert(s);

  if (new_size <= my_string_get_buffer_size(s))
    return (0);

  wchar_t *tmp = realloc(s->unicode, (new_size + 1) * sizeof(wchar_t));
  if (!tmp)
    return -1;

  s->unicode = tmp;
  s->buffer_size = new_size + 1;

  return (1);
}
