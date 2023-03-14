#include <stdio.h>
#include <stdlib.h>

int main()
{
    char pole[101]; //vzdy o jedno delsi nez max string, posledni misto je pro '\0'
    int i;
    int delka;
    delka = 0;
    scanf("%100[^\n]s", pole); // [^\n] naèítá i mezery mezi slovy, 100 nacita 100 znaku, aby se pole nepreplnilo
    //zde se nacita delka slova
    for(i = 0; pole[i] != '\0'; i++) //posledni znak pole je vzdy '\0'
    {
      delka++;
    }
    printf("\nDelka napsane vety je: %d znaku", delka);
    // zde bude cyklus pro vypis poctu cislic a pismen
    int pocet_pismen;
    pocet_pismen = 0;
    int pocet_cisel;
    pocet_cisel = 0;
    for (i = 0; pole[i] != '\0'; i++)
    {
      if ((pole[i] >= 'A' && pole[i] <= 'Z') || (pole[i] >= 'a' && pole[i] <= 'z')) //zde pouziji znaky, ktere se prepocitaji do ascii (mohu je napsat jako cisla z ascii tabulky)
        {
          pocet_pismen++;
        }
      else if (pole[i] >= 48 && pole[i] <= 57) //zde pouziji
        {
          pocet_cisel++;
        }
    }
    printf("\nPocet cisel: %d", pocet_cisel);
    printf("\nPocet pismen: %d", pocet_pismen);

    return 0;
}
