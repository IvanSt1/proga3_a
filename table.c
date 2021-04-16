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
    while((i<t->csize) && (t->ks1[i].key!=k1)&&(strcmp(t->ks2[i].key,k2))) {
        i++;
    }
    if(i==t->csize)
        return NULL;
    else
        return t->ks1[i].info;
}
Item * findk1(Table *t,int k1){
    int i=0;
    while((i<t->csize) && (t->ks1[i].key!=k1)) {
        i++;
    }
    if(i==t->csize)
        return NULL;
    else
        return t->ks1[i].info;
}
Item * findkpar(Table *t,int kpar, int i){
    while((i<t->csize) && (t->ks1[i].par!=kpar) ){
        i++;
    }
    if(i==t->csize)
        return NULL;
    else
        return t->ks1[i].info;
}

int findk2(Table *t,char *k2){
    int i=t->csize-2;
    while((i>=0)&& (strcmp(t->ks2[i].key,k2)) ) {
        i--;
    }
    return i;
}
int findk2_fromBegin(Table *t,char *k2){
    int i=0;
    while((i<t->csize)&& (strcmp(t->ks2[i].key,k2)) ) {
        i++;
    }
    return i;
}



int insert(Table* t, int* k1, char *k2, char * info){
    if(findk1(t,k1)!=NULL) return 1;
    else{
        if(t->msize==t->csize) return 2;
        else{
            Item * item=malloc(sizeof(Item));
            item->key1=k1;
            item->key2=k2;
            item->inf=info;
            t->ks1[t->csize].key=k1;
            if(t->csize==0)
                t->ks1[t->csize].par=NULL;
            else
            {
                t->ks1[t->csize].par=t->ks1[rand() % (t->csize)].key;
            }
            t->csize++;
            int i= findk2(t, k2);
            if (i>=0){
                t->ks2[t->csize-1].key = k2;
                t->ks2[t->csize-1].realise = t->ks2[i].realise+1;
                t->ks2[i].next=(KeySpace2 *)malloc(sizeof(KeySpace2));
                (*t->ks2[i].next)=t->ks2[t->csize-1];
                item->realise=t->ks2[i].realise+1;
                t->ks2[t->csize-1].info = item;

            }
            else {
                item->realise=0;
                t->ks2[t->csize-1].key = k2;
                t->ks2[t->csize-1].realise = 0;
                t->ks2[t->csize-1].next=NULL;
                t->ks2[t->csize-1].info = item;
            }
            t->ks1[t->csize-1].info=item;
            return 0;
        }
    }
}

int delete(Table *t, int k1, char *k2){
    int i=0;
    while(i<t->csize && (strcmp(t->ks2[i].key,k2))&&(t->ks1[i].key!=k1)){
        i++;
    }
    if(i==t->csize) return 0;
    else{
        int k=t->ks1[i].key;
        free(t->ks1[i].info->inf);
        free(t->ks1[i].info);
        if(i!=t->csize-1){
            t->ks1[i]=t->ks1[(t->csize-1)];
        }

        t->csize=t->csize-1;
        for(int i=0; i<t->csize;i++){
            if (t->ks1->par==k)
                t->ks1->par=0;
        }
        return 1;
    }
}