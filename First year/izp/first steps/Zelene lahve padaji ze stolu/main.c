#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    x = 15;
    do
    {
      printf("%d zelenych lahvi stoji na stole a 1 lahev spadne\n", x);
      x--;
    } while (x >= 5);

    for (x = 4; x > 1; x--)
    {
      printf("%d zelene lahve stoji na stole a 1 lahev spadne\n", x);
    }
    printf("%d zelena lahev stoji na stole a 1 lahev spadne\n", x);
    return 0;
}
