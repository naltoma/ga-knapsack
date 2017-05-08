#include "parameter.h"
#include "KP.h"

extern int *item;
extern char *itemfile;
extern int *weight;

void read_itemfile(); /* ナップサック問題を読み込む */


void read_itemfile()
{
    FILE *read_file;
    int count;
    char buff[1024];

    read_file = fopen(itemfile,"r");
    count = 0;
    while( count < ITEM_NUM ){
	fgets(buff, sizeof(buff), read_file);
	sscanf(buff,"%d %d",&(*(item+count)),&(*(weight+count)));
	count++;
    }
    (void)fclose(read_file);
}
