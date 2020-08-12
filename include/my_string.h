#ifndef LIBMY_STRING_H
#define LIBMY_STRING_H

#include <wchar.h>

typedef struct {
  wchar_t *unicode;

  long size;
  long buffer_size;
} my_string;

#define my_string_get_size(s) (s)->size
#define my_string_get_buffer_size(s) (s)->buffer_size
#define my_string_get_text(s) (s)->unicode

my_string *my_string_create(wchar_t *unicode, long n);
void my_string_destroy(my_string *s);

int my_string_append(my_string *dest, wchar_t *src, long n);
int my_string_append_wr(my_string *dest, my_string *src, long n);

int my_string_check_capacity(my_string *s, long new_size);

my_string *my_string_clone(my_string *s);

my_string *my_string_concat(my_string *s1, my_string *s2);

int my_string_delete_char(my_string *s, wchar_t c);

long my_string_count_char(my_string *s, wchar_t c);

my_string *my_string_create_from_char(wchar_t c, long count);

void my_string_bubblesort(my_string *s, int (*f)(wchar_t, wchar_t));

int my_string_ascending(wchar_t a, wchar_t b);
int my_string_descending(wchar_t a, wchar_t b);

#endif
