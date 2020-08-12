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
    if (!bang || s_append_wr(s, bang, 1) < 0)
      return 1;

    test_case("My String::Append", {
      expect("string matches", !wcscmp(L"Hello, 世界!", s_text(s)));
      expect("size", s_size(s) == wcslen(s_text(s)));
      expect("buffer size", s_bufsize(s) == 50);
    });

    my_string *concat = s_concat(s, s);
    if (!concat)
      return 1;

    test_case("My String::Concat", {
      expect("string matches", !wcscmp(L"Hello, 世界!Hello, 世界!", s_text(concat)));
      expect("size", s_size(concat) == wcslen(s_text(concat)));
      expect("buffer size", s_bufsize(concat) == 50);
    });

    my_string *foo = s_create(L"foobarfoo", 9);
    if (!foo)
      return 1;

    s_delete_char(foo, L'o');

    test_case("My String::Delete Char", {
      expect("string matches", !wcscmp(L"fbarf", s_text(foo)));
      expect("size updated", s_size(foo) == 5);
    });

    test_case("My String::Count Char", {
      expect("count two", s_count_char(foo, L'f') == 2);
      expect("count zero", s_count_char(foo, L'z') == 0);
    });

    my_string *manyfs = s_create_from_char(L'f', 10);
    if (!manyfs)
      return 1;

    test_case("My String::Create From Char", {
      expect("string matches", !wcscmp(L"ffffffffff", s_text(manyfs)));
      expect("size", s_size(manyfs) == 10);
    });

    my_string *unsorted = s_create(L"abczdefghkimj", 0);
    if (!unsorted)
      return 1;

    my_string_bubblesort(unsorted, my_string_ascending);

    test_case("My String::Bubblesort", {
      expect("ascending", !wcscmp(L"abcdefghijkmz", s_text(unsorted)));

      my_string_bubblesort(unsorted, my_string_descending);
      expect("descending", !wcscmp(L"zmkjihgfedcba", s_text(unsorted)));
    });

    s_destroy(concat);
    s_destroy(s);
    s_destroy(bang);
    s_destroy(foo);
    s_destroy(manyfs);

    return 0;
}
