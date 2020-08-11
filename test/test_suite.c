#define MINIUNIT_MAIN
#include "miniunit.h"

/* library to test */
#include "../include/my_string.h"

#include <locale.h>

int main()
{
    (void)setlocale(LC_ALL, "");

    my_string *s = my_string_create(L"Hello, 世界", 9);
    my_string *bang = my_string_create(L"!!!!", 4);

    test_case("Basic Unicode", {
      expect("right size", s->size == 9);
      expect("initial buffer size", s->buffer_size == 50);
      expect("string matches", !wcscmp(L"Hello, 世界", s->unicode));
    });

    int i = my_string_append_wr(s, bang, 1);

    test_case("Append", {
      expect("return value", !i);
      expect("string matches", !wcscmp(L"Hello, 世界!", s->unicode));
      expect("size after append", s->size == 10);
      expect("buffer size after append", s->buffer_size == 50);
    });

    my_string_destroy(s);
    my_string_destroy(bang);

    return 0;
}
