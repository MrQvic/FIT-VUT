#include <stdio.h>
#include <stdlib.h>
#define SUMA 5 // z kolika cisel budeme pocitat/hledat minimum a maximum
int main()
{
    int i;
    int cisla[SUMA];

    for (i = 0; i < SUMA; i++)
    {
      printf("Zadej cislo: ");
      scanf("%d", &cisla[i]);
    }

    int maximum;
    maximum = cisla[0]; //zadefinujeme si maximum jako prvni cislo pole a dale s nim budeme pracovat
    int minimum;
    minimum = cisla[0]; // zadefinujeme si minimum jako prvni cislo pole a dale s nim budeme pracovat
    float prumer;
    prumer = 0;

    for (i = 0; i < SUMA; i++)
    {
      //vypocet maxima
      if (cisla[i] > maximum)  //pokud je cislo v danem poli (v poli 0, 1, pak 2 atd..) vetsi nez cislo v prvnim poli (pole cisla[0]), potom se hodnota priradi k maximu
      {
        maximum = cisla[i]; // zde se priradi
      }
      //vypocet minima
      if (cisla[i] < minimum) //stejny princip jako nahore
      {
        minimum = cisla[i];
      }
      prumer = prumer + cisla[i];
    }
    printf("Minimum je: %d\n", minimum);
    printf("Maximum je: %d\n", maximum);
    printf("Prumer je: %f", prumer/SUMA);

    return 0;
}
