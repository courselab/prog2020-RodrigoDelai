/* m004.c - Binary to decimal.

   This program takes a string read as a command line argument and,
   interpreting it as a positive binary integer, outputs its
   corresponding value in decimal base.


   E.g.

      command line    : m004 0011
      expected output : 3

   Directions:

      Please, edit function decimal();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Return the value in decimal base of the string b, interpreted
   as the a positive binary number. If the string contains any
   characters other than '1's and '0's, truncate the string
   right before the spurious character (eg. truncate 110x001
   into 110); an empty string means zero. */


int pot(int b,int e)
{
    int i;
    int a=1;

    for(i=0;i<e;i++)
    {
        a=a*b;
    }
    return a;
}

int decimal (char *b)
{
  int n=2;
  int i=0;
  int j=0;
  int c=0;
  
  n = strlen(b);

  for (i=n-1;i>=0;i--)
    {
      if (b[i]-48<0)
        {
          c=0; j=0;
        }
      else
        if (b[i]-48>1)
          {
            c=0; j=0;
          }
        else
          {
            c=c+(b[i]-48)*pot(2,j);
            j++;
          }
    }
  return c;
}

#define USAGE "m004 <string>\n"

/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;

  if (argc < 2)
    {
      printf (USAGE);
      exit(1);
    }

  n = decimal (argv[1]);

  printf ("%d\n", n);

  return 0;
}
