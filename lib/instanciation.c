#include <wchar.h>
#include <string.h>
#include <stdlib.h>

#include "../include/my_string.h"

static my_string *my_string_init(my_string *s, int type, int buffer_size) {
  if (!s)
    return (NULL);

  s->size = 0;
  s->buffer_size = buffer_size;
  s->type = type;
  s->ascii = NULL;
  s->unicode = NULL;

  if (s->type == MY_STRING_ASCII) {
    s->ascii = malloc(buffer_size);
    if (!s->ascii)
      return (NULL);
    memset(s->ascii, 0, buffer_size);
  } else if (s->type == MY_STRING_UNICODE) {
    s->unicode = malloc(sizeof(wchar_t) * buffer_size);
    if (!s->unicode)
      return (NULL);
    wmemset(s->unicode, 0, buffer_size);
  }

  return (s);
}

my_string *my_string_create(char *ascii, wchar_t *unicode) {
  int type;
  if (!ascii && unicode)
    type = MY_STRING_UNICODE;
  else if (ascii && !unicode)
    type = MY_STRING_ASCII;
  else
    return (NULL);

  my_string *s = malloc(sizeof(my_string));
  if (!s)
    return (NULL);

  int length;
  if (type == MY_STRING_UNICODE)
    length = wcslen(unicode);
  else
    length = strlen(ascii);

  if (!my_string_init(s, type, length + 1)) {
    free(s);
    return (NULL);
  }
  if (type == MY_STRING_UNICODE)
    wcscpy(s->unicode, unicode);
  else
    strcpy(s->ascii, ascii);

  s->size = length;

  return (s);
}

void my_string_destroy(my_string *s) {
  free(s->unicode);
  free(s->ascii);
  memset(s, 0, sizeof(my_string));
  free(s);
}
