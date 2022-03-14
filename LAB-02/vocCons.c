#include "funct.h"

int main(int argc, char  *argv[]) {

  if(argc>=2)
  {
    char **p;
    p = vocali_consonanti(argv[1]);
    printf("vocali: %s\n",p[0]);
    printf("consonanti: %s\n",p[1]);
  }
  return 0;
}
