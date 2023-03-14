/*
 * Autor: Adam Mrkva
 * xmrkva04
 */
#include <stdio.h>
#include <stdlib.h>

//funkce pro porovnani retezcu
int porovnej_retezce(char retezec1[], char retezec2[], int delka)
{
    for (int i = 0; i < delka; i++)
    {
      if(retezec1[i] != retezec2[i])
      {
        return 1;
      }
    }
    return 0;
}

//funkce pro zjisteni delky stringu - vlastni alternativa k strlen
int delka_stringu(char pole[])
{
  int i;
  for(i = 0; pole[i] != '\0'; i++)
  {
  }
  return i;
}

//funkce pro zjisteni delky stringu (jen po znak \n)
int delka_stringu2(char pole[])
{
  int i;
  for(i = 0; pole[i] != '\n'; i++)
  {
  }
  return i;
}

//pravidlo 1 - funkce pro nalezeni malych a velkych pismen
int pravidlo_1(char pole[])
{
    int velka_pismena = 0;
    int mala_pismena = 0;
    for(int i = 0; pole[i] != '\0'; i++)
    {
      if (pole[i] >= 'a' && pole[i] <= 'z') //pokud najdu male pismeno, pridam k mala_pismena 1
      {
        mala_pismena++;
      }
      else if (pole[i] >= 'A' && pole[i] <= 'Z') //pokud najdu velke pismeno, pridam k velka_pismena 1
      {
        velka_pismena++;
      }
    }
    if (mala_pismena >= 1 && velka_pismena >= 1) //pokud jsou mala a velka pismena aspon 1, vratim 0. Jinak vratim 1
    {
      return 0;
    }
    else
    {
      return 1;
    }
}

//pravidlo 2, cast 2 - pomocna funkce pro funkci "najdi_znaky_z_x_skupin" - bere v potaz zadany parametr a podle nej vraci vysledek
int rozhodni_zda_plati(int mala, int velka, int cisla, int specialni, int hodnota_param)
{
    if (hodnota_param == 1) //pripad, kdy parametr je 1
    {
      if ((mala >= 1) || (velka >= 1) || (cisla >= 1) || (specialni >= 1)) //staci, aby jedna z podminek byla splnena a vrati 0
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (hodnota_param == 2) //pripad, kdy parametr je 2
    {
      //pokud plati alespon 1 z techto dvojic podminek, vrati 0
      if((mala >= 1 && velka >= 1) || (mala >= 1 && cisla >= 1 ) || (mala >= 1 && specialni >= 1 ) || (velka >= 1 && cisla >= 1) || (velka >= 1 && specialni >= 1) || (cisla >= 1 && specialni >= 1))
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (hodnota_param == 3) //pripad, kdy parametr je 3
    {
      //pokud plati alespon 1 z techto trojic podminek, vrati 0
      if((mala >= 1 && velka >= 1 && cisla >= 1) || (mala >= 1 && cisla >= 1 && specialni >= 1 ) || (mala >= 1 && specialni >= 1 && velka >= 1 ) || (velka >= 1 && cisla >= 1 && specialni >= 1))
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (hodnota_param >= 4) //pripad, kdy parametr je 3
    {
      //pokud neplati alespon 1 z podminek, vrati 1
      if ((mala < 1) || (velka < 1) || (cisla < 1) || (specialni < 1))
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    return 1;
  }

//pravidlo 2 - funkce pro nalezeni znaku z X skupin
int pravidlo_2(char pole[], int hodnota_param)
{
    //zadam si skupiny znaku podle zadani
    int mala_pismena = 0;
    int velka_pismena = 0;
    int cisla = 0;
    int specialni_znaky = 0;
    for(int i = 0; pole[i] != '\0'; i++) //pomoci cyklu postupne naskenuji jednotlive znaky a rozdelim je do skupin
    {
      if (pole[i] >= 'a' && pole[i] <= 'z') //skupina malych pismen
      {
        mala_pismena++;
      }
      else if (pole[i] >= 'A' && pole[i] <= 'Z') //skupina velkych pismen
      {
        velka_pismena++;
      }
      else if (pole[i] >= '0' && pole[i] <= '9') //skupina cisel
      {
        cisla++;
      }
      //skupina specialnich znaku podle zadani (32-126)
      else if ((pole[i] >= 32 && pole[i] <= 47 ) || (pole[i] >= 58 && pole[i] <= 64 ) || (pole[i] >= 91 && pole[i] <= 96 ) || (pole[i] == 123 ))
      {
        specialni_znaky++;
      }
    }
    //zavolam jinou - pomocnou funkci, abych nemel jednu prilis dlouhou
    if (rozhodni_zda_plati(mala_pismena, velka_pismena, cisla, specialni_znaky, hodnota_param) == 0) //pokud funkce vrati hodnotu 0, tato funkce vrati take hodnotu 0
    {
      return 0;
    }
    else
    {
      return 1;
    }
}

//pravidlo 3 - funkce pro nalezeni sekvence znaku v hesle
int pravidlo_3(char pole[], int hodnota_param)
{
    int sekvence = 1; //zadam si int pro ukladani delky sekvence jako cislo
    for(int i = 0; pole[i] != '\0'; i++) //projedu cele pole znak po znaku
    {
      if (pole[i] == pole[i+1]) //pokud se rovna znak se znakem o 1 dal, pridam k hodnote sekvence 1
      {
        sekvence++;
      }
      if (sekvence >= hodnota_param) //pokud se sekvence rovna, nebo je vetsi nez zadany parametr, vratim 1 -> heslo se zahodi
      {
        return 1;
      }
      if (pole[i] != pole[i+1]) //podminka pro restart pocitadla, pokud po sobe jdouci znaky nejsou shodne.
      {
        sekvence = 1;
      }
    }
    return 0;
}

//pravidlo 4 - funkce pro nalezeni stejnych sekvenci v hesle
int pravidlo_4(char pole[], int hodnota_param)
{
    int delka;
    //urcim delku hesla a odectu delku nacitanych sekvenci (abych za koncem hesla nesahal do pameti do ktere nemam)
    delka = (delka_stringu(pole) - hodnota_param);
    char *sekvence1;
    char *sekvence2;
    //nacitam substring o urcite delce od zacatku
    for(int i = 0; i < delka; i++)
    {
      sekvence1 = &pole[i]; //vytvoreni prvni sekvence
      //nacitam substring o urcite delce o znak dal nez predchozi substring
      for(int j = i + 1; j < delka; j++)
      {
        sekvence2 = &pole[j]; //vytvoreni druhe sekvence o znak dal, abych neporovnaval dve totozne
        if(porovnej_retezce(sekvence1, sekvence2, hodnota_param) == 0) //pokud se sekvence rovnaji, vratim 1 a heslo zahodim
        {
          return 1;
        }
      }
    }
    return 0; //pokud se zadne substringy nerovnaji, cyklus dojde do konce a funkce vrati 0
}

//hlavni funkce
int main(int argc, char *argv[])
{
    //kontrola argc
    if ((argc > 4) || (argc < 3) ) //vypisu error, pokud pocet argumentu presahne 3
    {
      fprintf(stderr, "Neocekavany pocet argumentu!\n");
      return 1;
    }

    //kontrola argv[1]
    //vytahnu si ze stringu argumentu int(hodnota_level) pres strtol, zbytek se uklada do p_1
    char *p_1;
    int hodnota_level;
    hodnota_level = strtol(argv[1], &p_1, 10);
    if (p_1[0] != '\0') //pokud adresa ukazatele obsahuje nejaky znak, vypisu chybu
    {
      fprintf(stderr, "Neocekavany vstup argumentu LEVEL!\n");
      return 1;
    }
    else if (hodnota_level < 1 || hodnota_level > 4) //porovnam prevedeny string s ocekavanou hodnotou vstupu
    {
      fprintf(stderr, "Neocekavany vstup argumentu LEVEL!\n");
      return 1;
    }

    //kontrola argv[2]
    //budu postupvat podobne jako pri kontrole argv[1]
    char *p_2;
    int hodnota_param;
    hodnota_param = strtol(argv[2], &p_2, 10);
    if (p_2[0] != '\0')
    {
      fprintf(stderr, "Neocekavany vstup argumentu PARAM!\n");
      return 1;
    }
    else if (hodnota_param < 1)
    {
      fprintf(stderr, "Neocekavany vstup argumentu PARAM!\n");
      return 1;
    }

    //kontrola argv[3]
    //postupovat lze i pres strtol, ale prislo mi logictejsi pouzit mozna nepekny loop
    int i = 0;
    int udelej_statistiku = 0;
    while(i < 1)
    {
      i++;
      if (argv[3] == NULL) //pokud je argv[3] prazdne, zrusim cyklus pokracuji dal
      {
        break;
      }
      if (porovnej_retezce("--stats", argv[3], 8) == 0) //pokud se argv[3] rovna "--stats", zrusim cyklus a zapisu do promenne pro provedeni statistiky
      {
        udelej_statistiku = 1;
        break;
      }
      fprintf(stderr, "Neocekavany tvar argumentu --stats!\n"); //pokud se argv[3] nerovna --stats a ani neni prazdny, vypisu error
      return 1;
    }

    //promenne ke statistice
    int nejkratsi_heslo = 101;
    float celkem_znaku = 0;
    float celkem_hesel = 0;
    char unikatni_znaky[96] = {0};//pole si vynuluju, aby se mi v nem neobjevily nezadouci znaky
    int pocitadlo = 0;
    int x = 0;
    //kontrola jednotlivych hesel
    char heslo[103];
    while(fgets(heslo, 103, stdin) != NULL) //zde naskenuji 1 radek a dale s nim pracuji
    {
      //kontrola, zda neni string prilis dlouhy
      if (delka_stringu(heslo) > 101) //zde 100 + 1, protoze moje funkce pripocita \n (viz. jak funguje .txt v linuxu)
      {
        fprintf(stderr, "\nNeocekavana delka hesla!\n");
        return 1;
      }

      //statistika
      if (udelej_statistiku == 1)
      {
        //nejkratsi heslo
        if (delka_stringu2(heslo) < nejkratsi_heslo)
        {
          nejkratsi_heslo = delka_stringu2(heslo);
        }
        //prumerna delka hesla, samotny vypocet probiha az na konci hlavni funkce
        celkem_znaku = celkem_znaku + delka_stringu2(heslo);
        celkem_hesel = celkem_hesel + 1;
        //pocet unikatnich znaku
        for(int i = 0; heslo[i] != '\n'; i++) //skenuji po znaku na konec heslka (\n)
        {
          int j = 0;
          for(j = 0; unikatni_znaky != '\0'; j++) //kazdy znak z hesla porovnam s polem unikatni_znaky
          {
            if (unikatni_znaky[j] == heslo[i]) //pokud se znak shodne, cyklus se prerusi a vezme se dalsi znak
            {
              break;
            }
            if (unikatni_znaky[j] != heslo[i]) //pokud se neshodne, prictu k pocitadlu 1
            {
              pocitadlo++;
            }
          }
          //pokud je na pocitadlu vetsi hodnota nez delka pole s unikatnimi znaky, zapisu znak z nacteneho hesla na konec pole
          if (delka_stringu(unikatni_znaky) < pocitadlo)
          {
            unikatni_znaky[x] = heslo[i];
            unikatni_znaky[x+1] = '\0'; //za zapsany znak pro jistotu zapisu jeste \0, abych se vyhnul chybam
            x++;
          }
          pocitadlo = 0; //vynuluji pocitadlo, abych s nim mohl znovu pracovat
        }
        //printf("unikatni_znaky: %s\n", unikatni_znaky);
      }

      //provedeni jednotlivych pravidel
      if (hodnota_level == 1) //pokud argument LEVEl je 1
      {
        //zavolam funkci pro kontrolu pres pravidlo 1
        if (pravidlo_1(heslo) == 0) //pokud mi funkce vrati hodnotu 0, heslo proslo pravidlem, tudiz jej mohu vytisknout
        {
          fprintf(stdout, "%s", heslo);
        }
      }
      else if (hodnota_level == 2) //pokud argument LEVEl je 2
      {
        if ((pravidlo_1(heslo) == 0) && (pravidlo_2(heslo, hodnota_param) == 0)) //pokud heslo projde pravidlem 1 i pravidlem 2, vypisu jej
        {
          fprintf(stdout, "%s", heslo);
        }
      }
      else if (hodnota_level == 3) //pokud argment LEVEl je 3
      {
        if ((pravidlo_1(heslo) == 0) && (pravidlo_2(heslo, hodnota_param) == 0) && (pravidlo_3(heslo, hodnota_param) == 0))
        {
          fprintf(stdout, "%s", heslo);
        }
      }
      else if (hodnota_level >= 4) //pokud argment LEVEl je 4
      {
        if ((pravidlo_1(heslo) == 0) && (pravidlo_2(heslo, hodnota_param) == 0) && (pravidlo_3(heslo, hodnota_param) == 0) && (pravidlo_4(heslo, hodnota_param) == 0))
        {
          fprintf(stdout,"%s", heslo);
        }
      }
    }
    float prumerna_delka = celkem_znaku / celkem_hesel; //vypocet prumerne delky hesla
    if (udelej_statistiku == 1)
    {
      printf("Statistika:\nRuznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %.1f\n", delka_stringu(unikatni_znaky), nejkratsi_heslo, prumerna_delka);
    }
    //printf("unikatni_znaky: %s\n", unikatni_znaky);
    //printf("celkem_unikatnich_znaku: %d\n", celkem_unikatnich_znaku);
    return 0;
}
