#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substitution_validate_key(char* key, char* uppercase_key);

int main(int argc, char** argv) {
  // parse args
  if (argc < 2) {
    printf("please enter a key and a string to encrypt");
    return 1;
  } else if (argc > 3) {
    printf("usage: substitution [KEY] \"[INPUT]\"");
    return 1;
  }

  char key[27] = {0};
  int err;
  err = substitution_validate_key(argv[1], key);
  if (err) {
    return 1;
  }

  char* input = argv[2];
  char* output = calloc(strlen(input), sizeof(char));
  output[strlen(input)] = 0;

  char tmp;
  for (size_t i = 0; i < strlen(input); i++) {
    tmp = input[i];
    // only process letters
    if (tmp >= 'a' && tmp <= 'z') {
      tmp -= 'a';
      tmp = key[(size_t)tmp];
      tmp += 'a' - 'A';
    } else if (tmp >= 'A' && tmp <= 'Z') {
      tmp -= 'A';
      tmp = key[(size_t)tmp];
    }

    output[i] = tmp;
  }

  printf("%s\n", output);

  free(output);
  return 0;
}

int substitution_validate_key(char* key, char* uppercase_key) {
  if (strlen(key) != 26) {
    printf("please make sure the entered key is 26 characters long");
    return 1;
  }
  for (size_t i = 0; i < 26; i++) {
    // make sure key consists only of letters
    if ((key[i] < 'a' || key[i] > 'z') && (key[i] < 'A' || key[i] > 'Z')) {
      printf("please make sure the entered key contains only letters");
      return 2;
    }
    // make sure every letter appears only once
    char chr = key[i] > 'a' - 1 ? key[i] - ('a' - 'A') : key[i];

    if (strchr(uppercase_key, chr)) {
      printf(
          "please make sure the entered key contains every letter only once");
      return 3;
    }

    const char str_tmp[] = {chr, 0};
    strcat(uppercase_key, str_tmp);
  }

  return 0;
}