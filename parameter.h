
#include <stdio.h>
#include <stdlib.h>   /* srand(3), rand(3), malloc(3) for BSD/OS 3.0 */

#include "KP.h"


/* Please include KP.h before this file. */

#define POP_SIZE    50         /* ���Ŀ� */
#define GENE_LENGTH (ITEM_NUM) /* ������Ĺ */

#define ELITE_COPY  0.1        /* ���꡼����ά����¸������ */
#define CROS_RATE   0.8        /* �򺵳�Ψ */
#define MUTE_RATE   0.1        /* �����Ѱ۳�Ψ */

