
#include "parameter.h"

void mutation_binary();

extern int gene[POP_SIZE][GENE_LENGTH];
extern int random_i(int n);


/*
  ### binary string�Ѥ������Ѱۥ��ڥ졼��

  Ǥ�դ�2�ӥåȤ�򴹤��롣

  ������
 */
void mutation_binary()
{
    int i;
    double r;
    int pos;
    int elite_num;   /* ���꡼����ά����¸�������ο� */

    /* initialize */
    elite_num = (int)(POP_SIZE * ELITE_COPY);

    for(i=elite_num; i<POP_SIZE; i++){
      r = random_i(10001)/(10000.0);
      if( MUTE_RATE > r ){
	pos = random_i(GENE_LENGTH);

	/* pos��� */
	if( gene[i][pos] == 0 ){
	  gene[i][pos] = 1;
	}else{
	  gene[i][pos] = 0;
	}
      }
    }   
}

