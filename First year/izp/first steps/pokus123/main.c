#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  char vysledek;
  printf("Vitej v mem kvizu...\n---------------------------------------\n");
  printf("1. Kdo zalozil Microsoft?\n a) Steve Jobs\n b) Tim Cook\n c) Bill Gates\n d) Mark Zuckerberg\n");
  scanf(" %c", &vysledek); //Pred %c zde patri mezera, jinak to pak dela bordel!!!
  if ((vysledek == 'c') || (vysledek == 'C'))
    {
      printf("Spravne!\n");
    }
  else
    {
      printf("Spatne!\n");
    }
  printf("2. Kdo vlastni MySQL?\n a) Microsoft\n b) Apple\n c) Google\n d) Oracle\n");
  scanf(" %c", &vysledek); //Pred %c zde patri mezera, jinak to pak dela bordel!!!
  if ((vysledek == 'd') || (vysledek == 'D'))
    {
      printf("Spravne!\n");
    }
  else
    {
      printf("Spatne!\n");
    }
  printf("3. Jaky je code name pro Android 5?\n a) Kit Kat\n b) Lollipop\n c) Cupcake\n d) Jelly Bean\n");
  scanf(" %c", &vysledek); //Pred %c zde patri mezera, jinak to pak dela bordel!!!
  if ((vysledek == 'b') || (vysledek == 'B'))
    {
      printf("Spravne!\n");
    }
  else
    {
      printf("Spatne!\n");
    }
  return 0;
}
