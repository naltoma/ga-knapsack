
/*
  Program : random.c
  Comment : 乱数生成
  compile : % cc $filename
  include : stdlib.h
  Author  : 當間愛晃
  Date    : 1999.03.26
  Extra   : not yet.
 */

#include <stdio.h>
#include <stdlib.h>   /* srand(3), rand(3), malloc(3) for BSD/OS 3.0 */

void randomize();
int random_i(int n);
double random_d(int n);

/* シード値より乱数を生成 */
void randomize()
{
  unsigned int seed;
  printf("seed #:");
  scanf("%u",&seed);
  printf("\n");
  srand(seed);
}


/* 引数nより小さい正整数を生成 */
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
  ### 引数nより小さい実数を生成
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

