/* src: https://www.ibm.com/developerworks/library/l-gdb/eg2.c */

#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i;
  for(i = 0; i < 60; i++)
  {
    sleep(1);
  }

  return 0;
}

