#ifndef LIBMY_STRING_H
#define LIBMY_STRING_H

#include <wchar.h>

enum {
  MY_STRING_ASCII,
  MY_STRING_UNICODE
};

typedef struct {
  int type;

  char *ascii;
  wchar_t *unicode;

  long size;
  long buffer_size;
} my_string;

my_string *my_string_create(char *ascii, wchar_t *unicode);
void my_string_destroy(my_string *s);

int my_string_append(my_string *dest, void *src, long n);

#endif
