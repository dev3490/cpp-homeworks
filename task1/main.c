#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
  uintmax_t char_count = 0,
            word_count = 0,
            line_count = 0;

  FILE* file = argc > 1 ? fopen(argv[1], "r") : stdin;
  if (!file) {
      perror("File opening failed!!! Achtung!!!");
      return 1;
  }

  char c;
  while((c = fgetc(file)) != EOF) {
    switch (c) {
      case '\n':                                 ++line_count; __attribute__((fallthrough));
      case '\t': case '\v': case '\r': case ' ': ++word_count;
    }
    ++char_count;
    if (ferror(file)) puts("I/O error when reading");
  }

  printf("%ju\n%ju\n%ju\n", line_count, word_count, char_count);
}
