#include <assert.h>

#include "../../include/my_string.h"

my_string *my_string_concat(my_string *s1, my_string *s2) {
  assert(s1);
  assert(s2);

  my_string *concatenation = my_string_clone(s1);
  if (!concatenation || my_string_append_wr(concatenation, s2, 0) < 0)
    return (NULL);

  return (concatenation);
}
