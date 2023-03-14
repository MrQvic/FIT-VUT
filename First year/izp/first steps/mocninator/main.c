#include <stdio.h>
#include <stdlib.h>

int main()
{
    int zaklad;
    int exponent;
    int vysledek;
    int i;
    printf("Vitejte v mocninatoru!");
    printf("\n");
    printf("Zadej cislo, ktere mam umocnit:\n");
    scanf("%d", &zaklad);
    printf("Zadej exponent:\n");
    scanf("%d", &exponent);

    vysledek = zaklad;
    for (i=0; i < (exponent-1); i++)
    {
      vysledek = vysledek * zaklad;
    }
    printf("Vysledek je: %d", vysledek);
}
