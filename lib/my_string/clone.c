#include <wchar.h>
#include <assert.h>

#include "../../include/my_string.h"

my_string *my_string_clone(my_string *s) {
  assert(s);

  my_string *clone = my_string_create(L"", 0);

  if (!clone || my_string_append_wr(clone, s, 0) < 0)
    return NULL;

  return clone;
}
