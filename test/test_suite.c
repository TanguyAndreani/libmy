#define MINIUNIT_MAIN
#include "miniunit.h"

/* library to test */
#include "../include/my_string.h"

#include <locale.h>

int main()
{
    (void)setlocale(LC_ALL, "");

    my_string *s = my_string_create(NULL, L"Hello, 世界");
    wchar_t bang[] = L"!";

    test_case("Basic Unicode", {
      expect("right size", s->size == 9);
      expect("initial buffer size", s->buffer_size == 10);
      expect("type is unicode", s->type == MY_STRING_UNICODE);
      expect("same string", !wcscmp(L"Hello, 世界", s->unicode));

      my_string_append(s, bang, 1);
      expect("append", !wcscmp(L"Hello, 世界!", s->unicode));
    });

    my_string_destroy(s);

    my_string *s2 = my_string_create("Hello, World!", NULL);

    test_case("Basic Ascii", {
      expect("right size", s->size == 13);
      expect("initial buffer size", s->buffer_size == 14);
      expect("type is unicode", s->type == MY_STRING_ASCII);
      expect("same string", !strcmp("Hello, World!", s->ascii));
    });

    my_string_destroy(s2);

    return 0;
}
