#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datum_t
{
  int rok;
  int mesic;
  int den;
}DATUM;

int datum_kontrola(struct datum_t datum)
{
  if (datum.den > 31 || datum.den < 1)
    return -1;
  if (datum.mesic > 12 || datum.mesic < 0)
    return -1;
  if (datum.den == 31 && datum.mesic != 1 && datum.mesic != 3 && datum.mesic != 5 && datum.mesic != 7 && datum.mesic != 8 && datum.mesic != 10 && datum.mesic != 12)
    return -1;
  return 0;
}


int main()
{
  struct datum_t datum1, datum2;
  datum1.rok  = 1948;
  datum1.mesic = 12;
  datum1.den = 13;

  datum2.rok = 2012;
  datum2.mesic = 2;
  datum2.den = 30;

  if (datum_kontrola(datum1) == -1)
    return -1;
  if (datum_kontrola(datum2) == -1)
    return -1;
  return 0;


}
