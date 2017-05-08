
/*
  Program : random.c
  Comment : ��������
  compile : % cc $filename
  include : stdlib.h
  Author  : �c�Ԉ��W
  Date    : 1999.03.26
  Extra   : not yet.
 */

#include <stdio.h>
#include <stdlib.h>   /* srand(3), rand(3), malloc(3) for BSD/OS 3.0 */

void randomize();
int random_i(int n);
double random_d(int n);

/* �V�[�h�l��藐���𐶐� */
void randomize()
{
  unsigned int seed;
  printf("seed #:");
  scanf("%u",&seed);
  printf("\n");
  srand(seed);
}


/* ����n��菬�����������𐶐� */
/* 0 <= random(n) < n */
int random_i(int n)
{  
/*	double rand_max = 9007199254740991.0;*/
/*  double rand_max = 2147483647.0;*/
/*  double rand_max = 32767;*/
  double rand_max = RAND_MAX;
  double r;
  double r1,r2;
  
  r1=(double)rand();
  r2=(double)n;
  r=(int)(r1/rand_max*r2);
  if( r >= n ){
      r = n - 1;
  }

  return((int)r);  
}


/*
  ### ����n��菬���������𐶐�
  0 <= randam(n) < n
 */
double random_d(int n)
{
/*  double rand_max = 2147483647.0;*/
/*  double rand_max = 32767;*/
  double rand_max = RAND_MAX;
  double r;
  double r1,r2;

  r1=(double)rand();
  r2=(double)n;
  r=(r1/rand_max*r2);

  return(r);
}   /* end of randam_d() */

