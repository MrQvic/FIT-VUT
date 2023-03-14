#include <stdio.h>
#include <stdlib.h>

int porovnej_retezce(char *retezec1, char *retezec2, int hodnota_param)
{
    for (int i = 0; i < hodnota_param; i++)
    {
      if(retezec1[i] != retezec2[i])
      {
        return 1;
      }
    }
    return 0;

}

//funkce pro zjisteni delky stringu - vlastni alternativa k strlen
int delka_stringu(char *pole)
{
  int i;
  for(i = 0; pole[i] != '\0'; i++)
  {
  }
  return i;
}

int main()
{
    int hodnota_param = 3;
    char pole[] = "Hellopolenoello";
    int delka;
    delka = (delka_stringu(pole) - hodnota_param);
    char *substring1;
    char *substring2;
    for(int i = 0; i < delka; i++)
    {
      substring1 = &pole[i];
      for(int j = i + 1; j < delka; j++)
      {
        substring2 = &pole[j];
        if (porovnej_retezce(substring1, substring2, hodnota_param) == 0)
        {
          printf("Nasel jsem");
          return 0;
        }
      }
    }
    printf("Nenasel jsem");

}


