#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    float y;
    float soucet;
    float rozdil;
    float soucin;
    float podil;
    printf ("Vitej v Adamove kalkulacce \n");
    printf ("Zadej prvni hodnotu pro operaci: ");
    scanf ("%f", &x);
    printf ("Zadej druhou hodnotu pro operaci: ");
    scanf ("%f", &y);
    soucet = x + y;
    rozdil = x - y;
    soucin = x * y;
    podil = x / y;
    printf ("Soucet: " "%f \n", soucet);
    printf ("Rozdil: " "%f \n", rozdil);
    printf ("Soucin: " "%f \n", soucin);
    printf ("Podil: " "%f \n", podil);
}
