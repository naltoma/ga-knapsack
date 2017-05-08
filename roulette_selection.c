
#include "parameter.h"

void roulette_selection();

extern int gene[POP_SIZE][GENE_LENGTH];
extern int fitness[POP_SIZE];
extern int random_i(int n);


void roulette_selection()
{
    static int sum_of_fitness;
    static double border;
    static double r;
    static int i,j;
    static int num;
    int new_gene[POP_SIZE][GENE_LENGTH];
    int new_fitness[POP_SIZE];
    int elite_num;
    int sorted_index[POP_SIZE];
    int buff_i;

    /* initialize */
    elite_num = (int)(POP_SIZE * ELITE_COPY);
    for(i=0; i<POP_SIZE; i++){
      sorted_index[i] = 0;
    }
    /*****
      elite strategy
    *****/
    /* sorting by fitness */
    sorted_index[0] = 0;
    for(i=0; i<POP_SIZE; i++){
      sorted_index[i] = i;
    }

    for(i=0; i<POP_SIZE; i++){
      for(j=(i+1); j<POP_SIZE; j++){
        if( fitness[sorted_index[i]] < fitness[sorted_index[j]] ){
          buff_i = sorted_index[i];
          sorted_index[i] = sorted_index[j];
          sorted_index[j] = buff_i;
        }
      }
    }
    /* copy superior individual to new_gene */
    for(i=0; i<elite_num; i++){
      for(j=0; j<GENE_LENGTH; j++){
        new_gene[i][j] = gene[sorted_index[i]][j];
      }
      new_fitness[i] = fitness[sorted_index[i]];
    }

    /* copy superior individual to new_gene */
    sum_of_fitness = 0;
    for (i=0; i<POP_SIZE; i++)
	sum_of_fitness = sum_of_fitness + fitness[i];
        
    for (i=elite_num; i<POP_SIZE; i++){
        r = sum_of_fitness * (random_i(10001)/(10000.0));
        num = 0;
	border = fitness[0];

        while(border<r){
            num++;
	    border = border + fitness[num];
        }
/*	printf("select: gene no.%d\n",num);*/
        for (j=0;j<GENE_LENGTH;j++)
            new_gene[i][j] = gene[num][j];
        new_fitness[i] = fitness[num];
    }

    for(i=0; i<POP_SIZE; i++){
	for(j=0; j<GENE_LENGTH; j++)
	    gene[i][j] = new_gene[i][j];
	fitness[i] = new_fitness[i];
    }
}

