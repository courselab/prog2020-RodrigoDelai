/* m008.c - Lastname-Names.

   This program reads the name of a person from the standard input
   in the form 'First-name middle-names last-name' and outputs the 
   name in the form 'LAST-NAME, first-name middle-names'.
   The name should be entered using only ASCII characters (26 letter 
   of latim alphabet, no diacrictics).


   E.g.

      command line    : m008
      standard input  : John Little Bill Doe 
      expected output : DOE, John Little Bill

   Directions:

      Please, edit function lasname();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

/* Converts the string 's' from first-middle-last name 
   form into LAST-first-middle form. */

void lastname (char *s)
{
  int i;
  int n;
  int p=99;
  char t[MAX];

  n = strlen(s);

  for (i=n;s[i]!=32;i--)  /*Finding position of the last space. */
    p=i;
  
  for (i=p;i<n;i++)  /* Putting the last name in capital letters. */
    if (s[i]>96 && s[i]<123)
      s[i]=s[i]-32;

  strcpy(t,s);  /* Creating a auxiliar string. */

  for (i=0;i<p;i++)  /* Moving first and middle names to the end. */
    s[i+1+n-p]=t[i];
    
  for (i=0;i<n-p;i++)  /* Moving the last name to beginning. */
    s[i]=t[i+p];

  s[n-p-1]=',';  /* Adding a comma after the first name. */
  s[n-p]=32;  /* Adding a space after the comma. */

}

/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;
  char name[MAX];

  fgets (name, MAX-1, stdin);
  
  lastname (name);

  printf ("%s\n", name);
  
  return 0;
}
