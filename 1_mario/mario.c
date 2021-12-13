#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int input = 0;
  char* buffer;

  if (argv[1] != 0) {
    buffer = argv[1];
    input = strtol(buffer, 0, 10);
  }
  if (input < 1 || input > 8) {
    do {
      printf("Height: ");
      fgets(buffer, 3, stdin);
      fflush(stdin);
      input = strtol(buffer, 0, 10);
    } while (input < 1 || input > 8);
  }
  // printf("%d", input);
  // fflush(stdin);
  // getchar();

  for (int i = 1; i <= input; i++) {
    for (int j = 0; j < (input - i); j++) {
      printf(" ");
    }
    for (int j = 0; j < i; j++) {
      printf("#");
    }

    printf(" ");

    for (int j = 0; j < i; j++) {
      printf("#");
    }
    for (int j = 0; j < (input - i); j++) {
      printf(" ");
    }

    printf("\n");
  }

  return 0;
}