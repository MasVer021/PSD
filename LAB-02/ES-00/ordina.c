#include "funct.h"



int main(int argc, char *argv[])
{
  int i;

  if(argc>=2)
  {

    int *p= xmalloc((argc-1)*sizeof(int));

    for(i=1;i<argc;i++)
    {
        p[i-1]=atoi(argv[i]);
    }


    ordinaInt(p,argc-1);

    for(i=0;i<argc-1;i++)
    {
      printf("%d",p[i]);

    }
  }

  return 0;
}
