#include <stdio.h>

int main () {
   // int vetor [10];

  //  for (int i = 0; i < 10; i++) {
   //     printf("%d ",vetor [i]);    
   // }
   int x;
   int *ptr;

   x = 10;
   printf ("x: %d\n",x);
   ptr = &x;
   printf ("ptr: %p\n",ptr);
   printf("valor no endereço: %d\n",*ptr);
   x = 12;
   
   printf ("x: %d\n",x);
   printf("valor no endereço: %d\n",*ptr);


    return 0;
}