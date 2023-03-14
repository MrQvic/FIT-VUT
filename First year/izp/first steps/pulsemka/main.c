#include <stdio.h>
#include <stdlib.h>
//int a = 4;
//int b = 5;
//
//void test(int *c)//int *c = 8 (b)
//{
//  int a = *c;/*/ int a = 8 /*/ printf("%d %d ", a, b); // a = 8 b = 5
//  if (a > b) { a = b; }/*/ a = 5 /*/ else { int b = a; printf("%d %d ", a, b); }
//  *c = a; //b = 5
//}
//
//
//int main()
//{
// int b = 8; printf ("%d %d ", a , b);
// test(&b); printf("%d %d ", a, b);
// return 0;
//}
// 4 8 8 5 4 5

//int main()
//{
//    for(int i = -6;i++;)
//    {
//        printf("%d --- ",i);
//        printf("hodnota i je %d\n",++i);
//    }
//    return 0;
//}

int main()
{
  int *a, *b;
  b = NULL;
  //a = malloc(sizeof(int));
  *a = 14;
  b = a;
  *b = *b + *a * -3;
  printf("%d \n", *a);
}

