
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

    int elite_num;   /* ���꡼����ά����¸�������ο� */

    /* initialize */
    elite_num = (int)(POP_SIZE * ELITE_COPY);
    
    for(i=elite_num; i<(POP_SIZE-1); i=i+2){
	r = random_i(10001)/(10000.0);
	if( r <= CROS_RATE ){

	    for(j=0; j<GENE_LENGTH; j++){
		gene1[j] = gene[i][j];
		gene2[j] = gene[i+1][j];
	    }
	    
	    /* �����������Ƹ򺵰��֤���ꤷ�������ͤ�c_pos���������� */
	    c_pos = 0;
	    c_pos = random_i(GENE_LENGTH);

	    /* �� */
	    for(j=c_pos;j<GENE_LENGTH;j++){
		work = gene1[j];
		gene1[j] = gene2[j];
		gene2[j] = work;
	    }

	    /* gene�˥��ԡ� */
	    for(k=0; k<GENE_LENGTH; k++){
		gene[i][k] = gene1[k];
		gene[i+1][k] = gene2[k];
	    }
	}   /* end of if(c_rate) */

    }   /* end of for(i) */

}   /* end of singlepoint_crossover() */
