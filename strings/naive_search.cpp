//
// C program for A modified Naive Pattern Searching
// algorithm that is optimized for the cases when all
// characters of pattern are different
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/strings
// https://github.com/allalgorithms/cpp
//
// Contributed by: Tushar Kanakagiri
// Github: @tusharkanakagiri
//
#include <stdio.h>
#include <string.h>

/* A modified Naive Pettern Searching algorithn that is optimized
   for the cases when all characters of pattern are different */
void search(char pat[], char txt[])
{
   int M = strlen(pat);
   int N = strlen(txt);
   int i = 0;

   while (i <= N - M)
   {
      int j;

      /* For current index i, check for pattern match */
      for (j = 0; j < M; j++)
         if (txt[i + j] != pat[j])
            break;

      if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
      {
         printf("Pattern found at index %d \n", i);
         i = i + M;
      }
      else if (j == 0)
         i = i + 1;
      else
         i = i + j; // slide the pattern by j
   }
}

/* Driver program to test above function */
int main()
{
   char txt[] = ""; //Enter the entire string here
   char pat[] = ""; //Enter the string to be searched here
   search(pat, txt);
   return 0;
}
