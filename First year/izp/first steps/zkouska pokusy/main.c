#include <stdlib.h>
#include <stdio.h>
struct osoba{int vek; double vaha; int vyska;};
typedef struct osoba CLOVEK;
int main(void)
{CLOVEK c4 = {.vek = 30}; CLOVEK c3 = {.vyska = 175}; printf("%d", c4.vek);
return 0; }





