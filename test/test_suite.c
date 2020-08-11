#define MINIUNIT_MAIN
#include "miniunit.h"

/* library to test */
#include "../include/my_string.h"

#include <locale.h>

int main()
{
    (void)setlocale(LC_ALL, "");

    my_string *s = my_string_create(L"Hello, 世界");
    wchar_t bang[] = L"!";

    test_case("Basic Unicode", {
      expect("right size", s->size == 9);
      expect("initial buffer size", s->buffer_size == 10);
      expect("same string", !wcscmp(L"Hello, 世界", s->unicode));

      my_string_append(s, bang, 1);
      expect("append", !wcscmp(L"Hello, 世界!", s->unicode));
    });

    my_string_destroy(s);

    return 0;
}
