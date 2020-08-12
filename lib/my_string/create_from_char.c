#include <wchar.h>
#include <assert.h>

#include "../../include/my_string.h"

my_string *my_string_create_from_char(wchar_t c, long count) {
  assert(count >= 0);

  my_string *s = my_string_create(L"", 0);
  if (!s)
    return NULL;

  if (my_string_check_capacity(s, count) < 0) {
    my_string_destroy(s);
    return NULL;
  }

  for (long i = 0; i < my_string_get_buffer_size(s); i++)
    my_string_get_text(s)[i] = c;
  my_string_get_text(s)[count] = L'\0';

  s->size = count;

  return s;
}
