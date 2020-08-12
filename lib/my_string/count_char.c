#include <wchar.h>
#include <assert.h>

#include "../../include/my_string.h"

long my_string_count_char(my_string *s, wchar_t c) {
  assert(s);

  long count = 0;
  for (long i = 0; i < my_string_get_size(s); i++) {
    if (my_string_get_text(s)[i] == c)
      count++;
  }
  return count;
}
