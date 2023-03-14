#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a;
    float b;
    float c;
    printf("Zadejte postupne koeficienty a,b,c kvadraticke rovnice ax^2+bx+c=0 : \n");
    printf("a: ");
    scanf(" %f", &a); //lf jako double float, mezera pro ignor mezer
    printf("b: ");
    scanf(" %f", &b);
    printf("c: ");
    scanf(" %f", &c);
    if (a != 0)
    {
      //vypocet diskriminantu
      float d = b * b - 4 * a * c;
      if (d < 0)
      {
        printf("Vysel zaporny diskriminant - nema reseni v R");
      }
      else if (d == 0)
      {
        float x = -b / ( 2 * a );
      }
      else
      {
        double D = sqrt(d);
        double x1 = ( -b + D ) / ( 2 * a);
        double x2 = ( -b - D ) / ( 2 * a);
        printf("Koren x1: %lf\n", x1);
        printf("Koren x2: %lf\n", x2);
      }

    }
    else
      printf("Neni kvadraticka rovnice!");

  return 0;
}
