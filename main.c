#include"dialog.h"
#include <string.h>
#include "keyspace1.h"
#include "keyspace2.h"
#include "item.h"
#include "dialog.h"
#include "table.h"
#include <stdlib.h>
#include <stdio.h>
const char *msgs[]={"0. Quite", "1. Add", "2. Find", "3. Delete", "4. Show"};
const int NMgsgs=sizeof(msgs)/ sizeof(msgs[0]);
int (*f[])(Table *)={NULL,D_Add,D_Find,D_Delete,D_Show};
int main(){
    int size;
    printf("Enter max size of table\n");
    Get_Int(&size);
    Table table;
    table.ks1=malloc(sizeof(KeySpace1)*size);
    table.ks2=malloc(sizeof(KeySpace1)*size);
    table.msize=size;
    table.csize=0;
    int rc;
    while(rc=dialog(msgs,NMgsgs)){
        if(!f[rc](&table)){
            break;
        }
    }
    return 0;
}