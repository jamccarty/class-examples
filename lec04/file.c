#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* infile = NULL;
  FILE* outfile = NULL;

  infile = fopen("input.txt", "r");
  if (infile == NULL) {
    printf("Error: unable to open file %s\n", "input.txt");
    exit(1);
  }

  outfile = fopen("/home/jmccarty/class-examples/output.txt", "w");
  if (outfile == NULL) {
    printf("Error: unable to open outfile\n");
    exit(1);
  }

  int ch;  // EOF is not a char value, but is an int.
           // since all char values can be stored in int, use int for ch

  ch = getc(infile);      // read next char from the infile stream
  while (ch != EOF) {
    putc(ch, outfile);  // write char value to the outfile stream
    ch = getc(infile);      // read next char from the infile stream
  }

  fclose(infile);
  fclose(outfile);
}

