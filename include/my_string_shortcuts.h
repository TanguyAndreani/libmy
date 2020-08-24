#ifndef MY_STRING_SHORTCUTS_H
#define MY_STRING_SHORTCUTS_H

/* If your program is simple enough and doesn't risk nameclashes */

#define s_size(s) (s)->size
#define s_bufsize(s) (s)->buffer_size
#define s_text(s) (s)->unicode

#define s_append(s1, s2, n) \
  my_string_append((s1), (s2), (n))

#define s_append_wr(s1, s2, n) \
  my_string_append_wr((s1), (s2), (n))

#define s_create(s, n) \
  my_string_create((s), (n))

#define s_destroy(s) \
  my_string_destroy(s)

#define s_concat(s1, s2) \
  my_string_concat(s1, s2)

#define s_clone(s) \
  my_string_clone(s)

#define s_count_char(s, c) \
  my_string_count_char(s, c)

#define s_create_from_char(c, n) \
  my_string_create_from_char(c, n)

#define s_delete_char(s, c) \
  my_string_delete_char(s, c)

#define s_delete_word my_string_delete_word

#define s_shift_left(s, f, sz) \
  my_string_shift_left(s, f, sz)

#endif
