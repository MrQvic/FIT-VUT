#include <stdio.h>
#include <stdlib.h>
int main()
{
    int pole[10];
    int i;
    for (i = 0; i < 10; i++)
    {
      pole[i] = 10 - i;
    }
    for (i = 0; i < 10; i++)
    {
      printf("%d ", pole[0]);
    }

}
