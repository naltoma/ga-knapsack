
/*
  Program : initialize_gene_binary.c
  Comment : GA�ѥХ��ʥꥹ�ȥ�󥰤ν�����ĺ���
  compile : % cc $filename
  Author  : �Ĵְ���
  Date    : 1999.09.11
 */

#include "parameter.h"

extern int gene[POP_SIZE][GENE_LENGTH];   /* �����ҽ��� */
extern int random_i(int n);

void initialize_pop_binary(int seed);
void initialize_gene_binary(int *str);


/*
  ### GA�ѥХ��ʥꥹ�ȥ�󥰤ν�����Ĥκ���

  parameters;
     int seed; �������͡�

  return value;
     none.

  # ERROR CHECK
  none.
 */
void initialize_pop_binary(int seed)
{
    static int i;

    srand(seed);
    for(i=0; i<POP_SIZE; i++){

	/* gene���� */
	initialize_gene_binary(gene[i]);

    }   /* end of for(i) */
    
}   /* end of initialize_pop_binary() */


/*
  ### GA�ѥХ��ʥꥹ�ȥ�󥰤��ĺ���
  */
void initialize_gene_binary(int *str)
{
    int i;

    /* initialize */
    for(i=0; i<GENE_LENGTH; i++){
	*(str+i) = 0;
    }

    /* make binary string */
    for(i=0; i<GENE_LENGTH; i++){
	*(str+i) = random_i(2);
    }

}   /* end of nitialize_gene_binary() */
