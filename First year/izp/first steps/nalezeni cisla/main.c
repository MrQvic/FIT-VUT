#include <stdio.h>
#include <stdlib.h>

int vyskyt_cisla(int prvek)
{
  unsigned i;
  int mnozina[] = {1,2,3,4};
  for(i = 0; i < sizeof(mnozina) / sizeof(int) ; i++)
    {
      if (mnozina[i] == prvek)
      {
        return 1;
      }
    }
  return 0;
}

int main()
{
  if(vyskyt_cisla(3) == 1)
    {
      printf("Cislo je v intervalu");
    }
    else
      printf("Cislo neni v intervalu");

    return 0;
}
