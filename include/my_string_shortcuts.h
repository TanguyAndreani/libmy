#ifndef MY_STRING_SHORTCUTS_H
#define MY_STRING_SHORTCUTS_H

/* If your program is simple enough and doesn't risk nameclashes */

#define s_size(s)    (s)->size
#define s_bufsize(s) (s)->buffer_size
#define s_text(s)    (s)->unicode

#define s_append           my_string_append
#define s_append_wr        my_string_append_wr
#define s_create           my_string_create
#define s_destroy          my_string_destroy
#define s_concat           my_string_concat
#define s_clone            my_string_clone
#define s_count_char       my_string_count_char
#define s_create_from_char my_string_create_from_char
#define s_delete_char      my_string_delete_char
#define s_delete_word      my_string_delete_word
#define s_shift_left       my_string_shift_left

#endif
