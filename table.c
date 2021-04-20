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
Item * find(Table *t, int k1, char *k2){
    int i;
    for (i=0;i<t->msize1;i++){
        if (t->ks1[i].key!=0){
            if((t->ks1[i].key==k1)&&(strcmp(t->ks1[i].info->key2,k2)==0)) {
                break;
            }
        }
    }

    if(i==t->msize1)
        return NULL;
    else
        return t->ks1[i].info;
}
Item * findk1(Table *t,int k1){
    int i=0;
    while((i<t->msize1) && (t->ks1[i].key!=k1)) {
        i++;
    }
    if(i==t->msize1)
        return NULL;
    else
        return t->ks1[i].info;
}
KeySpace1 * findkpar(Table *t,int kpar,int *kol){
    KeySpace1 *ks1;
    *kol=0;
    ks1=(KeySpace1*)calloc(sizeof(KeySpace1),(*kol+1));
    for(int i=0; i<t->msize1;i++){
        if(t->ks1[i].key!=0){
            if(t->ks1[i].par==kpar){
                ks1=realloc( ks1,sizeof(KeySpace1)* (*kol + 1));
                ks1[*kol]=t->ks1[i];
                (*kol)++;
            }
        }
    }
    if (*kol==0)
        return NULL;
    else
        return ks1;
}




int insert(Table* t, int k1,int par, char *k2, char * information) {
    int h,i,a=0,x,kol;
    KeySpace2 *ks2,ks1;
    if (findk1(t, k1) != NULL) return 1;
    else {
        if (t->msize1 == t->csize1) return 2;
        else {
            if ((findk1(t, par) == NULL) && (par != 0)) return 3;
            else {
                Item *item = malloc(sizeof(Item));
                item->key1 = k1;
                item->key2 = k2;
                item->inf = information;
                   h=Hesh(t,k2);
                    if (t->ks2[h].realise==-1)
                    {
                        item->realise = 0;
                        t->ks2[h].key = k2;
                        t->ks2[h].realise = 0;
                        t->ks2[h].next = NULL;
                        t->ks2[h].info = item;
                    }
                    else
                    {
                        ks1.key=k2;
                        ks1.info=item;
                        ks1.next = NULL;
                        ks1.realise=t->ks2[h].realise+1;
                        item->realise = t->ks2[h].realise+1;
                        ks1.next=(KeySpace2*)calloc(sizeof (KeySpace2),1);
                        (*ks1.next)=t->ks2[h];
                        t->ks2[h]=ks1;
                    }
                for (int i=0; i<t->msize1;i++) {
                    if(t->ks1[i].key==0) {
                        t->ks1[i].key = k1;
                        t->ks1[i].par = par;
                        t->ks1[i].info = item;
                        break;
                    }
                }
                t->csize1++;
                return 0;
            }
        }
    }
}
KeySpace2 *findk2(Table*t, char* k2){
    int h= Hesh(t,k2);
    if (t->ks2[h].realise==-1){
        return 0;
    }
    else
        return &(t->ks2[h]);
}

int delete(Table *t, int k1, char *k2) {
    int i = 0;
    while (i < t->csize1 && (strcmp(t->ks2[i].key, k2)) && (t->ks1[i].key != k1)) {
        i++;
    }
    if (i == t->csize1) return 0;
    else {
        int k = t->ks1[i].key;
        free(t->ks1[i].info->inf);
        free(t->ks1[i].info);
        if (i != t->csize1 - 1) {
            t->ks1[i] = t->ks1[(t->csize1 - 1)];
        }

        t->csize1 = t->csize1 - 1;
        for (int i = 0; i < t->csize1; i++) {
            if (t->ks1->par == k)
                t->ks1->par = 0;
        }
        return 1;
    }
}