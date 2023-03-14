#include <stdio.h>
#include <stdlib.h>

int main()
{
    float (r);
    float (obsah);
    float (obvod);
    float (pi) = 3.1415; //pøeddefinovana hodnota pí
    printf("Vitej v kalkulacce pro vypocet obvodu a obsahu kruhu \n");
    printf("Hodnoty zadej v mm. Pi je dano jako 3.1415 \n");
    printf("Zadej polomer kruhu (mm): ");
    scanf ("%f", &r);
    if (r >= 0) //mùžeme dosadit pouze nezáporné èíslo
    {
      obvod = 2 * pi * r;
      obsah = pi * (r * r);
      printf ("Obsah zadaneho kruhu je: " "%f" " mm^2 \n", obsah);
      printf ("Obvod zadaneho kruhu je : " "%f" " mm \n", obvod);
    }
    else //pokud dosadíme záporné èíslo
    {
      printf ("Polomer nemuze byt zaporne cislo!\n");
    }
    return 0;
}
