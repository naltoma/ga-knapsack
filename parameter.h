
#include <stdio.h>
#include <stdlib.h>   /* srand(3), rand(3), malloc(3) for BSD/OS 3.0 */

#include "KP.h"


/* Please include KP.h before this file. */

#define POP_SIZE    50         /* 集団数 */
#define GENE_LENGTH (ITEM_NUM) /* 遺伝子長 */

#define ELITE_COPY  0.1        /* エリート戦略で保存する割合 */
#define CROS_RATE   0.8        /* 交叉確率 */
#define MUTE_RATE   0.1        /* 突然変異確率 */

