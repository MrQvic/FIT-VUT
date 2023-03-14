#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a;
  int b;
  int c;
  int vysledek;
  printf("Zadej cislo A: \n");
  scanf("%d", &a);
  printf("Zadej cislo B: \n");
  scanf("%d", &b);
  printf("Zadej cislo C: \n");
  scanf("%d", &c);
  vysledek = b * b - 4 * a * c;
  printf("Diskriminant je: %d", vysledek);


}
