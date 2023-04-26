#include <stdio.h>

int main(int argc, char *argv[])
{
   int sum;
   sum = 100;
   printf("argv adrs=%p\n", argv);
   for (int i = 0; i < argc; i++, sum += 10) {
     printf("arg[%d]adrs=%p\n", i, &argv[i]);
     printf("arg[%d]=%s\n", i, argv[i]);
     printf("sum=%d\n", sum);
   }
   printf("[End] sum=%d\n", sum);
}
