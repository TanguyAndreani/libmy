#include <wchar.h>
#include <assert.h>

#include "../../include/my_string.h"

/*
 * I tried to do something fancy here by making a O(2n) algorithm
 * instead of two imbricated for loops.
 *
 * Instead of doing (1.) remove the char (2.) shift the rest of the string
 * (3.) repeat for next char,
 *
 * I do (1.) remove all the chars (2.) shift the whole string by incrementing
 * a counter each time it passes a removed char.
 */

int my_string_delete_char(my_string *s, wchar_t c) {
  assert(s);
  assert(c != L'\0');

  for (long i = 0; i < my_string_get_size(s); i++) {
    if (my_string_get_text(s)[i] == c) {
      my_string_get_text(s)[i] = L'\0';
    }
  }

  long n = 0;
  for (long i = 0; i + n < my_string_get_size(s); i++) {
    my_string_get_text(s)[i] = my_string_get_text(s)[i + n];
    if (my_string_get_text(s)[i] == L'\0') {
      n++;
      i--;
    }
  }

  s->size -= n;

  return 0;
}
