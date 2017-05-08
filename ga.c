
/*
  Program : ga.c
  Comment : GA for `Knapsack Problem'
  compile : % make
  Author  : 當間愛晃
  Date    : 2000.01.24
 */

#include "parameter.h"
#include "KP.h"

/* global variables */
/* for Knapsack Problem */
int *item;
char *itemfile;
int *weight;

/* for GA */
int generation;
int gene[POP_SIZE][GENE_LENGTH];
int fitness[POP_SIZE];
int all_max_fitness;   /* 全世代における最大適応度 */
int all_max_fitness_generation;
int all_max_fitness_index;
int all_max_fitness_gene[GENE_LENGTH];
int all_max_weight;   /* 全世代における最大適応度となる解の総重量 */

void check_result();
void usage();


/* external functions */
void read_itemfile();
extern void initialize_pop_binary(int seed);
extern void calc_fitness_pop();
extern void roulette_selection();
extern void singlepoint_crossover();
extern void mutation_binary();


/* usage() */
void usage()
{
    /* read args: a.out $seed_pop $seed_ga $max_generaion */
    fprintf(stderr,"# USAGE: prompt> a.out $Seed_Pop $Seed_GA $ItemList_for_Knapsack $Terminate_Generation\n");
    fprintf(stderr,"   $Seed_Pop : Seed's value to make initial poplation.\n");
    fprintf(stderr,"   $Seed_GA  : Seed's value to perform GA's operator.\n");
    
    exit(-1);
}   /* end of usage() */


int main(int argc, char **argv)
{
    int i, j;
    int seed_pop; /* 初期集団生成用シード値 */
    int seed_ga;  /* GAオペレータ用シード値 */
    int max_generation; /* 終了条件：最終世代数 */
#ifdef STEPBYSTEP
    char buff[10];
#endif //STEPBYSTEP


    /* initialize */
    i = 0;
    j = 0;
    seed_pop = 0;
    seed_ga = 0;
    max_generation = 0;
    generation = 0;
    /* ナップサック問題読み込み用の変数初期化 */
    item = (int *)malloc(sizeof(int)*ITEM_NUM);
    if( item == NULL ){
      fprintf(stderr,"# ERROR! malloc() for item was failed in ga.c.\n");
      exit(-1);
    }
    itemfile = (char *)malloc(sizeof(char)*1024);
    if( itemfile == NULL ){
      fprintf(stderr,"# ERROR! malloc() for itemfile was failed in ga.c.\n");
      exit(-1);
    }
    weight = (int *)malloc(sizeof(int)*ITEM_NUM);
    if( weight == NULL ){
      fprintf(stderr,"# ERROR! malloc() for weight was failed in ga.c.\n");
      exit(-1);
    }

    /* 最終世代における最適解保存用変数を初期化 */
    all_max_fitness = 0;
    all_max_fitness_generation = 0;
    all_max_fitness_index = 0;
    all_max_weight = 0;

    /* 引数読み込み */
    if( argc != 5 ){
	usage();
    }else{
	seed_pop = atoi(argv[1]);
	seed_ga = atoi(argv[2]);
	itemfile = argv[3];
	max_generation = atoi(argv[4]);
    }
    fprintf(stderr,"# reading args => seed_pop=%d, seed_ga=%d, itemfile=%s, max_generation=%d\n",seed_pop,seed_ga,itemfile,max_generation);


    /* 初期集団生成 */
    initialize_pop_binary(seed_pop);
    for(i=0; i<POP_SIZE; i++){
	fprintf(stderr,"gene no.%d = ",i);
	for(j=0; j<GENE_LENGTH; j++){
	    fprintf(stderr,"%d ",gene[i][j]);
	}
	fprintf(stderr,"\n");
    }

    /* ナップサック問題読み込み */
    read_itemfile();
    for(i=0; i<ITEM_NUM; i++){
	fprintf(stderr,"item[%3d] = %d\n",i,*(item+i));
    };

    /* 適応度計算 */
    calc_fitness_pop();

    /* GA */
    for(generation=1; generation<max_generation; generation++){

	fprintf(stdout,"generation no.%d\n",generation);

#ifdef SELECTION
	/* ルーレット選択 */
	fprintf(stdout,"# roulette_selection().\n");
	roulette_selection();
#ifdef CHECK_POP
	check_result();
#endif CHECK_POP
#endif SELECTION

#ifdef CROSSOVER
	/* 交叉 */
	fprintf(stdout,"# singlepoint_crossover().\n");
	singlepoint_crossover();
#ifdef CHECK_POP
	check_result();
#endif CHECK_POP
#endif CROSSOVER

#ifdef MUTATION
	/* 突然変異 */
	fprintf(stdout,"# mutation().\n");
	mutation_binary();
#ifdef CHECK_POP
	check_result();
#endif CHECK_POP
#endif MUTATION

	/* 適応度計算 */
	calc_fitness_pop();
#ifdef CHECK_POP
	check_result();
#endif CHECK_POP

#ifdef STEPBYSTEP
	fgets(buff,sizeof(buff),stdin);
#endif STEPBYSTEP
    } /* for(generation) */


    /* output */

    fprintf(stdout,"## GA finished!\n");
    fprintf(stdout,"Best of fitness = %d\n",all_max_fitness);
    fprintf(stdout,"Generation no.%d\n",all_max_fitness_generation);
    fprintf(stdout,"gene no.%d = ",all_max_fitness_index);
    for(i=0; i<GENE_LENGTH; i++)
	fprintf(stdout,"%3d",all_max_fitness_gene[i]);
    fprintf(stdout,"\n");

    return( 0 );
}


void check_result()
{
    int i, j;

    for(i=0; i<POP_SIZE; i++){
	fprintf(stdout,"gene no.%d = ",i);
	for(j=0; j<GENE_LENGTH; j++){
	    fprintf(stdout,"%d ",gene[i][j]);
	}
	fprintf(stdout," => fitness = %d\n",fitness[i]);
    }

}
