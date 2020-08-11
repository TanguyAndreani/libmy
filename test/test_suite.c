#define MINIUNIT_MAIN
#include "miniunit.h"

/* library to test */
#include "../include/my_string.h"

#include <locale.h>

int main()
{
    (void)setlocale(LC_ALL, "");

    my_string *s = my_string_create(L"Hello, 世界");
    my_string *bang = my_string_create(L"!");

    test_case("Basic Unicode", {
      expect("right size", s->size == 9);
      expect("initial buffer size", s->buffer_size == 50);
      expect("same string", !wcscmp(L"Hello, 世界", s->unicode));

      my_string_append_wr(s, bang, 0);
      expect("append", !wcscmp(L"Hello, 世界!", s->unicode));
      expect("size after append", s->size == 10);
      expect("buffer size after append", s->buffer_size == 50);
    });

    my_string_destroy(s);

    return 0;
}
