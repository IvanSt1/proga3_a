#include"dialog.h"
#include <string.h>
#include "keyspace1.h"
#include "keyspace2.h"
#include "item.h"
#include "dialog.h"
#include "table.h"
#include <stdlib.h>
#include <stdio.h>
const char *msgs[]={"1. Quite","2. Add", "3. Find","4.Find All Versions", "5. Delete", "6. Show","7. Par Find"};
const int NMgsgs=sizeof(msgs)/ sizeof(msgs[0]);
int (*f[])(Table *)={NULL,D_Add,D_Find,D_Find_All_Versions,D_Delete, D_Show,D_ParFind};
int main(){
    int size;
    printf("Enter max size of table\n");
    Get_Int(&size);
    Table table;
    table.ks1=malloc(sizeof(KeySpace1)*size);
    table.ks2=malloc(sizeof(KeySpace2)*size);
    table.msize=size;
    table.csize=0;
    int rc;
    while(rc=dialog(msgs,NMgsgs)){
        if(!f[rc](&table)){
            break;
        }
    }
    free(table.ks1);
    free(table.ks2);
    return 0;
}