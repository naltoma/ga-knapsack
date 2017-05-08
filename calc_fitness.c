
/*
#include <stdio.h>
#include "KP.h"*/
#include "parameter.h"


extern int *item;
extern int *weight;
extern int generation;
extern int gene[POP_SIZE][GENE_LENGTH];
extern int fitness[POP_SIZE];
extern int all_max_fitness;
extern int all_max_fitness_generation;
extern int all_max_fitness_index;
extern int all_max_fitness_gene[GENE_LENGTH];
extern int all_max_weight;


void calc_fitness_pop();
double calc_fitness_gene(int gene_no);


/*
  ### GA集団全部の適応度計算
 */
void calc_fitness_pop()
{
    int i;
    int work_i;
    int index;

    /* initialize */
    work_i = 0;
    index = 0;

    for(i=0; i<POP_SIZE; i++){
	fitness[i] = calc_fitness_gene(i);

	/* check maximum fitness */
	if( work_i < fitness[i] ){
	    work_i = fitness[i];
	    index = i;
	}
    }

    if( work_i > all_max_fitness ){
	all_max_fitness = work_i;
	all_max_fitness_generation = generation;
	all_max_fitness_index = index;
	for(i=0; i<GENE_LENGTH; i++){
	    all_max_fitness_gene[i] = gene[all_max_fitness_index][i];
	}
	/* 重量再計算 */
	all_max_weight = 0;
	for(i=0; i<GENE_LENGTH; i++){
	  if( all_max_fitness_gene[i] == 1 ){
	    all_max_weight += *(weight+i);
	  }
	}


	/* output */
	fprintf(stdout,">> generation no.%d\n",all_max_fitness_generation);
	fprintf(stdout,">> max gene[%d] = ",all_max_fitness_index);
	for(i=0; i<GENE_LENGTH; i++)
	    fprintf(stdout,"%3d",all_max_fitness_gene[i]);
	fprintf(stdout,"\n");
	fprintf(stdout,">> Fitness = %d\n",all_max_fitness);

	fprintf(stderr,">> generation no.%d\n",all_max_fitness_generation);
	fprintf(stderr,">> max gene[%d] = ",all_max_fitness_index);
	for(i=0; i<GENE_LENGTH; i++)
	    fprintf(stderr,"%3d",all_max_fitness_gene[i]);
	fprintf(stderr,"\n");
	fprintf(stderr,">> Fitness = %d\n",all_max_fitness);

	/* gnuplot */
	fprintf(stdout,"MAX %d %d\n",all_max_fitness_generation,all_max_fitness);
    }

    /* gnuplot用データ */
    printf(">> max_fitness = %d %d\n",all_max_fitness,all_max_weight);

}   /* end calc_fitness_pop() */




/*
  ### 適応度計算
 */
double calc_fitness_gene(int gene_no)
{
    int i;
    int value_tmp;
    int weight_tmp;

    /* initialize */
    value_tmp = 0;
    weight_tmp = 0;

    for(i=0; i<GENE_LENGTH; i++){
	if( gene[gene_no][i] == 1 ){
	    value_tmp += *(item+i);
	    weight_tmp += *(weight+i);
	}
    }
    if( weight_tmp >= BAG_SIZE ){
	value_tmp = 0;
    }
    return( value_tmp );
    
}   /* end of calc_fitness_gene() */


