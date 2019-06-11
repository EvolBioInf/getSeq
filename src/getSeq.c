#include <bsd/stdlib.h>
#include "interface.h"
#include "eprintf.h"
#include <regex.h>
#include <stdio.h>
void scanFile(FILE *fp, Args *args, regex_t *re) {
  char *line = NULL;
  size_t len = 0;
  int match = 0;
   while (getline(&line, &len, fp) != -1) {
    if (line[0] == '>') {
        if (regexec(re, line, 0, NULL, 0) == 0)
          match = 1;
        else
          match = 0;
    }
    if ((match && !args->c) || (!match && args->c))
      printf("%s", line);
   }
   free(line);
}
int main(int argc, char **argv) {
  setprogname(argv[0]);
  Args *args = getArgs(argc, argv);
  if(args->v)
    printSplash(args);
  if(args->h || args->err)
    printUsage();
  regex_t re;
  if (regcomp(&re, args->s, REG_EXTENDED) != 0) {
    fprintf(stderr, "Error[%s] in regex: %s\n",
              getprogname(), args->s);
    exit(EXIT_FAILURE);
  }
  FILE *fp;
  if (args->nf == 0) {
    fp = stdin;
    scanFile(fp, args, &re);
  } else {
    for (int i = 0; i < args->nf; i++) {
      fp = efopen(args->fi[i], "r");
      scanFile(fp, args, &re);
      fclose(fp);
    }
  }
  freeArgs(args);
  regfree(&re);
  return 0;
}
