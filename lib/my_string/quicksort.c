#include <wchar.h>
#include <assert.h>

#include "../../include/my_string.h"

static void my_string_swap(wchar_t *text, long i, long j) {
  wchar_t tmp = text[i];
  text[i] = text[j];
  text[j] = tmp;
}

static long my_string_partition(wchar_t *text, long l, long r, int (*f)(wchar_t, wchar_t)) {
  wchar_t pivot = text[r];
  long i = l;

  for (long j = l; j < r; j++) {
    if (f(text[j], pivot) < 0) {
      my_string_swap(text, j, i);
      i++;
    }
  }
  my_string_swap(text, r, i);
  return i;
}

#define my_string_quicksort_push(v) stack[++idx] = (v)
#define my_string_quicksort_pop() (stack[idx--])

void my_string_quicksort(my_string *s, int (*f)(wchar_t, wchar_t)) {
  assert(s);
  assert(f);

  long l = 0;
  long r = my_string_get_size(s) - 1;

  long stack[r - l + 1];
  long idx = -1;

  my_string_quicksort_push(l);
  my_string_quicksort_push(r);

  while (idx >= 0) {
    r = my_string_quicksort_pop();
    l = my_string_quicksort_pop();

    long pivot_idx = my_string_partition(my_string_get_text(s), l, r, f);

    if (pivot_idx - 1 > l) {
      my_string_quicksort_push(l);
      my_string_quicksort_push(pivot_idx - 1);
    }

    if (pivot_idx + 1 < r) {
      my_string_quicksort_push(pivot_idx + 1);
      my_string_quicksort_push(r);
    }
  }
}

#undef my_string_quicksort_push
#undef my_string_quicksort_pop
