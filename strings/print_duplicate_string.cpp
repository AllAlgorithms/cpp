//
// C++ program to count all duplicates from string using hashing
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
#include <stdlib.h>
#define NO_OF_CHARS 256

/* Fills count array with frequency of characters */
void fillCharCounts(char *str, int *count)
{
  int i;
  for (i = 0; *(str + i); i++)
    count[*(str + i)]++;
}

/* Print duplicates present in the passed string */
void printDups(char *str)
{
  // Create an array of size 256 and fill count of every character in it
  int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
  fillCharCounts(str, count);

  // Print characters having count more than 0
  int i;
  for (i = 0; i < NO_OF_CHARS; i++)
    if (count[i] > 1)
      printf("%c,  count = %d \n", i, count[i]);

  free(count);
}

/* Driver program to test to pront printDups*/
int main()
{
  char str[] = ""; //Enter string here
  printDups(str);
  getchar();
  return 0;
}
