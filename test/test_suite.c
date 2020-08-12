#define MINIUNIT_MAIN
#include "miniunit.h"

/* library to test */
#include "../include/my_string.h"
#include "../include/my_string_shortcuts.h"

#include <locale.h>

int main()
{
    (void)setlocale(LC_ALL, "");

    my_string *s = s_create(L"Hello, 世界", 9);
    my_string *bang = s_create(L"!!!!", 4);

    test_case("Basic Unicode", {
      expect("right size", s_size(s) == 9);
      expect("initial buffer size", s_bufsize(s) == 50);
      expect("string matches", !wcscmp(L"Hello, 世界", s_text(s)));
    });

    int i = my_string_append_wr(s, bang, 1);

    test_case("Append", {
      expect("return value", !i);
      expect("string matches", !wcscmp(L"Hello, 世界!", s_text(s)));
      expect("size after append", s_size(s) == 10);
      expect("buffer size after append", s_bufsize(s) == 50);
    });

    my_string *concat = my_string_concat(s, s);

    test_case("Concat", {
      expect("return value", concat);
      expect("string matches", !wcscmp(L"Hello, 世界!Hello, 世界!", s_text(concat)));
      expect("size", s_size(concat) == 20);
      expect("buffer size", s_bufsize(concat) == 50);
    });

    s_destroy(concat);
    s_destroy(s);
    s_destroy(bang);

    return 0;
}
