#include <wchar.h>
#include <assert.h>

#include "../../include/my_string.h"
#include "../../include/my_string_shortcuts.h"

int my_string_shift_left(my_string *s, long from, long size) {
  assert(s);
  assert(from >= 0 && from < s_size(s));
  assert(size >= 0);

  for (long i = from; i+size <= s_size(s); i++) {
      s_text(s)[i] = s_text(s)[i+size];
  }

  s_size(s) -= size;

  return 0;
}
