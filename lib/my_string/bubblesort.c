#include <wchar.h>
#include <assert.h>

#include "../../include/my_string.h"

static void my_string_swap(wchar_t *text, long i, long j) {
  wchar_t tmp = text[i];
  text[i] = text[j];
  text[j] = tmp;
}

void my_string_bubblesort(my_string *s, int (*f)(wchar_t, wchar_t)) {
  assert(s);
  assert(f);

  int has_swap = 0;
  while (!has_swap) {
    has_swap = 0;
    for (long i = 0; i < my_string_get_size(s); i++) {
      for (long j = i; j < my_string_get_size(s); j++) {
        if (f(my_string_get_text(s)[i], my_string_get_text(s)[j]) > 0) {
          my_string_swap(my_string_get_text(s), i, j);
          has_swap = 1;
        }
      }
    }
  }
}
