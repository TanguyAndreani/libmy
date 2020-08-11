#define MINIUNIT_MAIN
#include "miniunit.h"

/* library to test */
#include "../include/my_string.h"
#include "../include/my_string_shortcuts.h"

#include <locale.h>

int main()
{
    (void)setlocale(LC_ALL, "");

    my_string *s = my_string_create(L"Hello, 世界", 9);
    my_string *bang = my_string_create(L"!!!!", 4);

    test_case("Basic Unicode", {
      expect("right size", my_string_get_size(s) == 9);
      expect("initial buffer size", my_string_get_buffer_size(s) == 50);
      expect("string matches", !wcscmp(L"Hello, 世界", s(s)));
    });

    int i = my_string_append_wr(s, bang, 1);

    test_case("Append", {
      expect("return value", !i);
      expect("string matches", !wcscmp(L"Hello, 世界!", s(s)));
      expect("size after append", my_string_get_size(s) == 10);
      expect("buffer size after append", my_string_get_buffer_size(s) == 50);
    });

    my_string_destroy(s);
    my_string_destroy(bang);

    return 0;
}
