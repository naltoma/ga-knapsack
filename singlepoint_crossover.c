
#include "parameter.h"

void singlepoint_crossover();

extern int gene[POP_SIZE][GENE_LENGTH];
extern int random_i(int n);


void singlepoint_crossover()
{
    int gene1[GENE_LENGTH];
    int gene2[GENE_LENGTH];
    unsigned char work;
    int           i,j,k;
    int           c_pos;
    double        r;

    int elite_num;   /* エリート戦略で保存した個体数 */

    /* initialize */
    elite_num = (int)(POP_SIZE * ELITE_COPY);
    
    for(i=elite_num; i<(POP_SIZE-1); i=i+2){
	r = random_i(10001)/(10000.0);
	if( r <= CROS_RATE ){

	    for(j=0; j<GENE_LENGTH; j++){
		gene1[j] = gene[i][j];
		gene2[j] = gene[i+1][j];
	    }
	    
	    /* 乱数を持ちいて交叉位置を決定し、その値をc_posへ代入する */
	    c_pos = 0;
	    c_pos = random_i(GENE_LENGTH);

	    /* 交叉 */
	    for(j=c_pos;j<GENE_LENGTH;j++){
		work = gene1[j];
		gene1[j] = gene2[j];
		gene2[j] = work;
	    }

	    /* geneにコピー */
	    for(k=0; k<GENE_LENGTH; k++){
		gene[i][k] = gene1[k];
		gene[i+1][k] = gene2[k];
	    }
	}   /* end of if(c_rate) */

    }   /* end of for(i) */

}   /* end of singlepoint_crossover() */
