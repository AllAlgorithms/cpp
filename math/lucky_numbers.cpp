// Lucky number implementation
// Carlos Abraham Hernandez
// algorithms.abranhe.com/math/lucky-numbers

#include <stdio.h> 
#define bool int 
  
/* Returns 1 if n is a lucky no. ohterwise returns 0*/
bool isLucky(int n) 
{ 
    static int counter = 2; 
      
    /*variable next_position is just for readability of 
        the program we can remove it and use n only */
    int next_position = n; 
    if(counter > n) 
        return 1; 
    if(n%counter == 0) 
        return 0;      
      
    /*calculate next position of input no*/
    next_position -= next_position/counter; 
      
    counter++; 
    return isLucky(next_position); 
} 
  
/*Driver function to test above function*/
int main() 
{ 
    int x = 7; 
    if( isLucky(x) ) 
        printf("%d is a lucky number.", x); 
    else
        printf("%d is not a lucky number.", x); 
    getchar(); 
} 
