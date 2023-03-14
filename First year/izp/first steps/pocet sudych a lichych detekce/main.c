#include <stdio.h>
#include <stdlib.h>


int main()
{
    int suda;
    suda = 0;
    int licha;
    licha = 0;
    int POCET; //pocet cisel v zadani
    POCET = 10;
    int i;

    printf("Zadej %d cisel, kazde odentruj..\n", POCET);
    for (i = 0; i < POCET; i++)
    {
      int cislo;
      scanf("%d", &cislo);
      if (cislo % 2 == 0)
      {
        suda++;
      }
      else
      {
        licha++;
      }
    }
    printf("Zadals %d sudych cisel\n", suda);
    printf("Zadals %d lichych cisel", licha);


}
