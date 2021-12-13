#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int points_table[26] = {
    1,   // A
    3,   // B
    3,   // C
    2,   // D
    1,   // E
    4,   // F
    2,   // G
    4,   // H
    1,   // I
    8,   // J
    5,   // K
    1,   // L
    3,   // M
    1,   // N
    1,   // O
    3,   // P
    10,  // Q
    1,   // R
    1,   // S
    1,   // T
    1,   // U
    4,   // V
    4,   // W
    8,   // X
    4,   // Y
    10   // Z
};

unsigned int scrabble_word_score(char* word);
int scrabble_validate_word(char* word);

int main(int argc, char** argv) {
  if (argc < 3) {
    printf(
        "please input two words in the program's arguments - scrabble word1 "
        "word2");
    return 1;
  }
  char* word1 = argv[1];
  char* word2 = argv[2];

  int err = 0;
  err += scrabble_validate_word(word1);
  err += scrabble_validate_word(word2);

  if (err) {
    printf("please make sure your input contains only scrabble valid letters");
    return 1;
  }

  unsigned int word1_score;
  unsigned int word2_score;

  word1_score = scrabble_word_score(word1);
  word2_score = scrabble_word_score(word2);

  printf("word1: %s - score: %d\n", word1, word1_score);
  printf("word2: %s - score: %d\n", word2, word2_score);

  if (word1_score > word2_score) {
    printf("%s wins with %d points\n", word1, word1_score);
  } else if (word1_score < word2_score) {
    printf("%s wins with %d points\n", word2, word2_score);
  } else {
    printf("words %s and %s tie with %d points\n", word1, word2, word1_score);
  }

  return 0;
}

unsigned int scrabble_word_score(char* word) {
  unsigned int score = 0;

  char* str_tmp = malloc((strlen(word) + 1) * sizeof(char));
  strcpy(str_tmp, word);

  for (size_t i = 0; i < strlen(word); i++) {
    if (str_tmp[i] > 96) str_tmp[i] -= 32;
    score += (points_table[(str_tmp[i] - 65)]);
  }

  free(str_tmp);
  return score;
}

int scrabble_validate_word(char* word) {
  for (size_t i = 0; i < strlen(word); i++) {
    if ((word[i] < 65 || word[i] > 90) && (word[i] < 97 || word[i] > 122))
      return -1;
  }
  return 0;
}