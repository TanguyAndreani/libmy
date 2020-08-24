#include <wchar.h>
#include <assert.h>

#include "../../include/my_string.h"
#include "../../include/my_string_shortcuts.h"

int my_string_delete_word(my_string *s, wchar_t *w, long n) {
  assert(s);
  assert(w);

  for (long i = 0; i < s_size(s); i++) {
      long j = i;
      while (j-i < n) {
          if (s_text(s)[j] != w[j-i]) {
              break;
          }
          j++;
      }
      if (j-i == n) {
          my_string_shift_left(s, i, n);
      }
  }

  return 0;
}
