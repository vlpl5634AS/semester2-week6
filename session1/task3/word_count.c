#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Read the file once and count lines, words and characters.
 * Returns 0 on success, -1 on failure.
 */
int count_file(const char *filename, size_t *out_lines, size_t *out_words, size_t *out_chars) {
  FILE *f = fopen(filename, "r");
  if (!f) {
    perror("Error opening file");
    return -1;
  }

  size_t lines = 0, words = 0, chars = 0;
  int in_word = 0;
  int c;

  while ((c = fgetc(f)) != EOF) {
    chars++;
    if (c == '\n') {
      lines++;
    }
    if (isspace((unsigned char)c)) {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      words++;
    }
  }

  fclose(f);

  if (out_lines) *out_lines = lines;
  if (out_words) *out_words = words;
  if (out_chars) *out_chars = chars;
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 1;
  }

  const char *filename = argv[1];
  size_t lines = 0, words = 0, chars = 0;

  if (count_file(filename, &lines, &words, &chars) != 0) {
    return 1;
  }

  printf("%zu lines\n", lines);
  printf("%zu words\n", words);
  printf("%zu characters\n", chars);

  return 0;
}
