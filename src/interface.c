/***** interface.c **********************************************************
 * Description: Get gequence from FASTA file
 * Author: Bernhard Haubold
 * Email: haubold@evolbio.mpg.de
 * License: GNU General Public License, https://www.gnu.org/licenses/gpl.html
 * Date: Sat Jun  8 10:03:38 2019
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <bsd/stdlib.h>
#include "interface.h"
#include "eprintf.h"

Args *newArgs() {
  Args *args = (Args *)emalloc(sizeof(Args));
  args->h   = 0;
  args->v   = 0;
  args->err = 1;
  args->s   = NULL;
  args->c   = 0;
  return args;
}

void freeArgs(Args *args) {
  free(args->s);
  free(args);
}

Args *getArgs(int argc, char *argv[]) {
  int c;
  char *optString = "hvcs:";
  Args *args = newArgs();

  while ((c = getopt(argc, argv, optString)) != -1) {
    switch(c) {
    case 's': /* regular expression */
      args->s =estrdup(optarg);
      args->err = 0;
      break;
    case 'c':
      args->c = 1;
      break;
    case 'h': /* help       */
      args->h = 1;
      break;
    case 'v': /* version    */
      args->v = 1;
      break;
    case '?':
      args->err = 1;
      if(optopt == 'i')
	fprintf(stderr, "Error: Option `%c` requires an argument.\n", optopt);
      else if(isprint(optopt))
	fprintf(stderr, "Error: Unknown option `%c`.\n", optopt);
      else
	fprintf(stderr, "Error: Unknown option character `\\x%x`.\n", optopt);
    default:
      args->err = 1;
      return args;
    }
  }
  args->fi = argv + optind;
  args->nf = argc - optind;

  return args;
}

void printUsage() {
  printf("Usage: %s [options] [inputFiles]\n", getprogname());
  printf("Get sequence whose header matches a regex\n");
  printf("Example: %s -s regex foo.fasta\n", getprogname());
  printf("Options:\n");
  printf("\t-s <REGEX> search for regular expression]\n");
  printf("\t[-c complement]\n");
  printf("\t[-h print this help message and exit]\n");
  printf("\t[-v print version & program information and exit]\n");
  exit(0);
}

void printSplash(Args *args) {
  printf("%s ", getprogname());
  int l = strlen(VERSION);
  for(int i = 0; i < l - 1; i++)
    printf("%c", VERSION[i]);
  printf(", %s\n", DATE);
  printf("Author: Bernhard Haubold\n");
  printf("License: GNU General Public License, https://www.gnu.org/licenses/gpl.html\n");
  printf("Bugs: haubold@evolbio.mpg.de\n");
  exit(0);
}
