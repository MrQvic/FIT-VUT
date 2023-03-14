#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
   char str[20];
   fgets(str, 20, stdin);
   printf("%s", str);
}
