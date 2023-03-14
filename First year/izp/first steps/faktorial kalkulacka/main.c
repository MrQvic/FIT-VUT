#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int POCET;
    POCET = 8;
    int pole[POCET];
    printf("napis %d cisel, kazde odentruj..\n", POCET);
    for (i > 0; i < POCET; i++)
    {
      scanf("%d", &pole[i]);

    }
    i = 0;
    printf("Napsals cisla: ");
    for (i > 0; i < POCET; i++)
    {
      printf("%d", pole[i]);
    }
    i = POCET;
    printf("\ntyto cisla obracene: ");
    for (i <= POCET; i > 0;)
    {
      --i;
      printf("%d", pole[i]);
    }

    return 0;
}
