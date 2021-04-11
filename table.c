#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "keyspace1.h"
#include "keyspace2.h"
#include "item.h"


Item * find(Table *ptab,int k1, char *k2){
    int i=0;
    while(i<ptab->csize && (strcmp(ptab->ks2[i].key,k2))&&(ptab->ks1[i].key==k1))
        i++;
    printf("%d\n",i);
    if(i==ptab->csize) return NULL;
    else return ptab->ks1[i].info;
}

int insert(Table* ptab, int* k1, char *k2, char * info){
    if(find(ptab,k1,k2)!=NULL) return 1;
    else{
        if(ptab->msize==ptab->csize) return 2;
        else{
            Item * item=malloc(sizeof(Item));
            item->key1=k1;
            item->key2=k2;
            item->inf=info;
            ptab->ks1[ptab->csize].key=k1;
            ptab->ks1[ptab->csize].info=item;
            ptab->ks2[ptab->csize].key=k2;
            ptab->ks2[ptab->csize].info=item;
            ptab->csize++;
            return 0;
        }
    }
}

int delete(Table *ptab, int k1, char *k2){
    int i=0;
    while(i<ptab->csize && (strcmp(ptab->ks2[i].key,k2))&&(ptab->ks1[i].key==k1)){
        i++;
    }
    if(i==ptab->csize) return 0;
    else{
        free(ptab->ks1[i].info->inf);
        free(ptab->ks1[i].info);
        if(i!=ptab->csize-1){
            ptab->ks1[i]=ptab->ks1[(ptab->csize-1)];
        }

        ptab->csize=ptab->csize-1;
        return 1;
    }
}