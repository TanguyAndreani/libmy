#ifndef LIBMY_STRING_H
#define LIBMY_STRING_H

#include <wchar.h>

enum {
  MY_STRING_ASCII,
  MY_STRING_UNICODE
};

typedef struct {
  wchar_t *unicode;

  long size;
  long buffer_size;
} my_string;

my_string *my_string_create(wchar_t *unicode);
void my_string_destroy(my_string *s);

int my_string_append(my_string *dest, wchar_t *src, long n);
int my_string_append_wr(my_string *dest, my_string *src, long n);

#endif
