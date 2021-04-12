#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "keyspace1.h"
#include "keyspace2.h"
#include "item.h"


Item * find(Table *t,int k1, char *k2){
    int i=0;
    while((i<t->csize) && (t->ks1[i].key!=k1)) {
        i++;
    }
    printf("%d\n",i);
    if(i==t->csize) return NULL;
    else return t->ks1[i].info;
}

int insert(Table* t, int* k1, char *k2, char * info){
    if(find(t,k1,k2)!=NULL) return 1;
    else{
        if(t->msize==t->csize) return 2;
        else{
            Item * item=malloc(sizeof(Item));
            item->key1=k1;
            item->key2=k2;
            item->inf=info;
            t->ks1[t->csize].key=k1;
            t->ks1[t->csize].info=item;
            t->ks2[t->csize].key=k2;
            t->ks2[t->csize].info=item;
            t->csize++;
            return 0;
        }
    }
}

int delete(Table *t, int k1, char *k2){
    int i=0;
    while(i<t->csize && (strcmp(t->ks2[i].key,k2))&&(t->ks1[i].key==k1)){
        i++;
    }
    if(i==t->csize) return 0;
    else{
        free(t->ks1[i].info->inf);
        free(t->ks1[i].info);
        if(i!=t->csize-1){
            t->ks1[i]=t->ks1[(t->csize-1)];
        }

        t->csize=t->csize-1;
        return 1;
    }
}