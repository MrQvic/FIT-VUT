#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf ("zadej cislo, ktere chces zdvojnasobit: ");
    scanf ("%d", &a);
    a = a * 2;
    printf ("vysledne cislo je: " "%d", a);
    return 0;
}
