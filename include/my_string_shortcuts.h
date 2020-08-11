#ifndef MY_STRING_SHORTCUTS_H
#define MY_STRING_SHORTCUTS_H

/* If your program is simple enough and doesn't risk nameclashes */

#define s_size(s) (s)->size
#define s_bufsize(s) (s)->buffer_size
#define s_text(s) (s)->unicode

#define s_append(s1, s2, n) \
  my_string_append((s1), (s2), (n))

#define s_append_wr(s1, s2, n) \
  my_string_append((s1), (s2), (n))

#define s_create(s, n) \
  my_string_create((s), (n))

#define s_destroy(s) \
  my_string_destroy(s)

#endif
