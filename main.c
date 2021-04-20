#include"dialog.h"
#include <string.h>
#include "keyspace1.h"
#include "keyspace2.h"
#include "item.h"
#include "dialog.h"
#include "Get.h"
#include "table.h"
#include <stdlib.h>
#include <stdio.h>
const char *msgs[]={"1. Quite","2. Add", "3. Find","4. Par Find", "5. Delete", "6. Show","7. Find all realise"};
const int NMgsgs=sizeof(msgs)/ sizeof(msgs[0]);
int (*f[])(Table *)={NULL,D_Add,D_Find,D_ParFind,D_Delete, D_Show,D_Find_Realise};
int main(){
    int size1,size2,len;
    printf("Enter max size of ks1 table\n");
    Get_Int(&size1);
    printf("Enter max size of ks2 table\n");
    Get_Int(&size2);
    printf("Length of key2\n");
    Get_Int(&len);
    Table table;
    table.ks1=calloc(sizeof(KeySpace1),size1);
    table.ks2=calloc(sizeof(KeySpace2),size2);
    table.msize1=size1;
    table.csize1=0;
    table.msize2=size2;
    table.strl=len;
    for (int i=0; i<size2;i++){
        table.ks2[i].realise=-1;
    }
    for (int i=0; i<size1;i++){
        table.ks1[i].key=0;
    }
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