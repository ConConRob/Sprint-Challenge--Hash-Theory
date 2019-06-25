#ifndef utils_h
#define utils_h

int check_strings(char *input, char *expected)
{
  for ( ; *input == *expected; input++, expected++) {
    if (*input == '\0') {
      return 0;
    }
  }
    
  return *input - *expected;
}

int check_string_arrays(char **input, char **expected, int n, int m)
{
  int i;

  if (n != m) {
    return 0;
  }

  for (i = 0; i < n; i++) {
    if (check_strings(input[i], expected[i]) != 0) {
      return 0;
    }
  }

  return 1;
}

#endif