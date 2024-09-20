#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int safe_parse_int(const char *str, int *out_value) {
  char *endptr;
  errno = 0; // Reset errno before the call
  long val = strtol(str, &endptr, 10);

  // overflow/underflow condition for long
  if (errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) {
    return 0;
  }

  // checking for no conversion
  if (endptr == str) {
    return 0;
  }

  // checking for total conversion
  if (*endptr != '\0') {
    return 0;
  }

  // overflow/underflow condition for int
  if (val < INT_MIN || val > INT_MAX) {
    return 0;
  }

  // successful conversion
  *out_value = (int)val;
  return 1;
}

int main() {
  const char *str = "10";
  int result;

  if (safe_parse_int(str, &result)) {
    printf("Int of string '%s' is %d\n", str, result);
  } else {
    printf("Failed to parse '%s' as an integer.\n", str);
  }

  return 0;
}
