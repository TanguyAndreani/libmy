#include <wchar.h>

int my_string_ascending(wchar_t a, wchar_t b) {
  if (a < b) {
    return -1;
  } else if (a > b) {
    return 1;
  } else {
    return 0;
  }
}

int my_string_descending(wchar_t a, wchar_t b) {
  if (a > b) {
    return -1;
  } else if (a < b) {
    return 1;
  } else {
    return 0;
  }
}
