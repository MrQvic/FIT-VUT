#include <stdio.h>
#include <stdlib.h>

int main()
{
    char pole[101];
    scanf("%100[^\n]s", pole);
    int i;
    for(i = 0; pole[i] != '\0' ; i++)
    {
      if (pole[i] >= 'A' && pole[i] <= 'Z')
      {
        pole[i] = pole[i] + 32;
      }
    }
    printf("%s", pole);
    return 0;
}
