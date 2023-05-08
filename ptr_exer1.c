#include <stdio.h>

#define ARY_MAX 3



int main(int argc, char *argv[])
{
   char inp_ary1[][8] = {"Appl", "Orang", "Banan"};
   for(int i=0; i<ARY_MAX; i++) {
     printf("Before str ary[%d]=%s/n", i, inp_ary[i]);
   }





   printf("Apple/n", "Orange/n", "Banana/n");
   return 0;
}



char **get_modify_str_ary() {
  char add_str[][2] = {"e", "e", "e"};

}
