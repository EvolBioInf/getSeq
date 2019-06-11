/***** interface.h **********************************************************
 * Description: Get gequence from FASTA file
 * Author: Bernhard Haubold
 * Email: haubold@evolbio.mpg.de
 * License: GNU General Public License, https://www.gnu.org/licenses/gpl.html
 * Date: Sat Jun  8 10:03:38 2019
 ****************************************************************************/
#ifndef INTERFACE
#define INTERFACE

#define DEFAULT_I 1

/* define argument container */
typedef struct args{
  char    h; /* help message?         */
  char    v; /* version message?      */
  char  err; /* error                 */
  int     i; /* iterations            */
  char **fi; /* input files           */
  char   *s; /* regular expression    */
  char    c; /* complement?           */
  int    nf; /* number of input files */
} Args;

Args *getArgs(int argc, char *argv[]);
Args *newArgs();
void freeArgs(Args *args);
void printUsage();
void printSplash(Args *args);

#endif
