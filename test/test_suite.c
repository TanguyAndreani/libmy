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
    if (!s)
      return 1;

    test_case("My String::Create", {
      expect("string matches", !wcscmp(L"Hello, 世界", s_text(s)));
      expect("size", s_size(s) == wcslen(s_text(s)));
      expect("buffer size", s_bufsize(s) == 50);
    });


    my_string *bang = s_create(L"!!!!", 4);
    if (!bang || my_string_append_wr(s, bang, 1) < 0)
      return 1;

    test_case("My String::Append", {
      expect("string matches", !wcscmp(L"Hello, 世界!", s_text(s)));
      expect("size", s_size(s) == wcslen(s_text(s)));
      expect("buffer size", s_bufsize(s) == 50);
    });

    my_string *concat = my_string_concat(s, s);
    if (!concat)
      return 1;

    test_case("My String::Concat", {
      expect("string matches", !wcscmp(L"Hello, 世界!Hello, 世界!", s_text(concat)));
      expect("size", s_size(concat) == wcslen(s_text(concat)));
      expect("buffer size", s_bufsize(concat) == 50);
    });

    my_string *foo = my_string_create(L"foobarfoo", 9);
    if (!foo)
      return 1;

    my_string_delete_char(foo, L'o');

    test_case("My String::Delete Char", {
      expect("string matches", !wcscmp(L"fbarf", s_text(foo)));
    });

    s_destroy(concat);
    s_destroy(s);
    s_destroy(bang);
    s_destroy(foo);

    return 0;
}
