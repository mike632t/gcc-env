/*
 *
 * env.c - Display environment vairables.
 *
 * Copyright(C) 2018   MEJT
 * 
 * This program optionally prints any environment vairables and command line
 * arguments, while demonstrating one technique for including optional debug
 * code that is ignored if debugging is not enabled.  This technique has the
 * advantage that it works with ANSI C compilers and that it can also be put
 * around blocks of code to enable/disable them as required.  The only small
 * problem is that the debug code is not parsed by the compiler if it is not
 * enabled, which can be a problem when maintaining code.
 *
 * This  program is free software: you can redistribute it and/or modify  it
 * under  the  terms of the GNU General Public License as published  by  the
 * Free  Software  Foundation, either version 3 of the License, or (at  your
 * option) any later version.
 *
 * This  program  is  distributed in the hope that it will  be  useful,  but
 * WITHOUT   ANY   WARRANTY;   without  even   the   implied   warranty   of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 *
 * You  should have received a copy of the GNU General Public License  along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * 07 Apr 13        - Initial version - MEJT
 * 24 Feb 16  0.1   - Lists environemnt vairables - MEJT
 * 22 Apr 18        - Added DEBUG macro - MEJT
 * 
 */
  
#include <stdio.h>
#include <stdlib.h>

/* Execute code if DEBUG is True */
#define debug(code) do {if(DEBUG){code;}} while(0)

/* Print to stderr with additional debug information if DEBUG is True */
#define print(_fmt, ...) do \
   { \
      if(DEBUG){ \
         fprintf(stderr,   "Debug   : %s line : %d (%s) : " _fmt "\n", \
            __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
      } \
   } while(0)

#define DEBUG 1 /* Enable debugging*/

int main(int argc, char **argv, char **envp){
   register char **pointer; /* Used as a pointer to the string arrays */
   register int count; 
   int status = 0;
  
   /* Print out the argument list using the number of arguments in argc */
   debug(
   fprintf(stderr, "Argv[]\t: ");
   for(pointer = argv; argc > 0; argc--,pointer++){
      fprintf(stderr, "%s", *pointer);
      /* Print spaces between arguments and a newline at the end */
      if(argc >1)fprintf(stderr, " "); else fprintf(stderr, "\n");
   });
  
   #undef DEBUG  /* Redefine DEBUG to disable debugging */
   #define DEBUG 0
  
   /* Print the current environment vairables
    * Note - The environment table is terminated by a NULL entry, so we just
    * loop while the pointer isn't a NULL */
   for(pointer = envp; *pointer; pointer++){ 
      debug(fprintf(stderr, "%s\n", *pointer)); /* Use debug inside loop */
   }
  
   #undef DEBUG /* Redefine DEBUG to enable debugging */
   #define DEBUG 1

   if(status)fprintf(stderr, "Error\n"); else print("Status\t: %d", status);
  
   exit(status);
}
