#include <stdio.h>
#include <string.h>


int quadrato(int n);
int euclide(int n, int m);
int palindroma(char *s ,int l);
int tartaglia(int a , int b);

int main (void)
{
  printf("%d\n",quadrato(-10) );
  printf("%d\n",euclide(130,494));
  printf("%d\n",palindroma("ansna",5));
  printf("%d\n",tartaglia(5,3));

}

int euclide(int n, int m)
{
  if(n%m>0)
	{
		euclide(m,n%m);
	}
	else
	{
		return m;
	}

}

int quadrato(int n)
{
  if(n<0)
  {
    return quadrato(-n);
  }

  if(n==0)
  {
    return 0;
  }

  return quadrato(n-1) +((2*n)-1);

}


int palindroma(char *s , int l)
{
  if(l<2)
  {
    return 1;
  }

  if(s[0] == s[l-1])
  {
    return palindroma(++s,l-2);
  }
  else
  {
    return 0;
  }
}


int tartaglia(int a , int b)
{
  if(a == b || b == 1 )
  {
    return 1;
  }

  return tartaglia(a-1,b-1)+tartaglia(a-1,b);
}
