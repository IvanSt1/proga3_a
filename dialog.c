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
const char *errmsgs[]={"OK","Duplicate key", "Table overflow", "Wrong parent key"};
int D_Add(Table*ptab){
    int rc;
    int l;
    int k1;
    int par;
    char* k2=NULL;
    char* info;
    printf("Enter key1: -->");
    Get_Int(&k1);
    printf("Enter parent key: -->");
    Get_Int0(&par);
    printf("Enter key2: -->");
    k2=Get_Strk2(ptab);
    if(k2==NULL)
        return 0;
    printf("Enter info:\n");
    info=Get_Str();
    if(info==NULL)
        return 0;
    rc=insert(ptab,k1,par,k2,info);
    printf("%s: %d, %s\n",errmsgs[rc],k1,k2);
    return 1;
}

int dialog(const char *msgs[], int n){
    char *errmsg="";
    int rc;
    int i,p;
    do{
        puts(errmsg);
        errmsg="You are wrong";
        for(i=0;i<n;++i)
            puts(msgs[i]);
        puts("Make your choise: -->");
        p=Get_Int(&rc);
        if(p==0)
            rc=0;
    }while(rc<0 || rc>n);
    rc--;
    return rc;
}

int D_Find(Table*ptab){
    /*int l;
    int k1;
    char* k2=NULL;
    Item* rc=NULL;
    printf("Enter key1: -->");
    Get_Int(&k1);
    printf("Enter key2: -->");
    k2=Get_Strk2(ptab);

    if(k2==NULL)
        return 0;
    rc=find(ptab,k1,k2);
    if(rc==NULL){
        printf("There is not such key.");
        return 1;
    }
    else{
        printf("key1: %d | key2: %s | info: %s | realise: %d\n",rc->key1,rc->key2,rc->inf,rc->realise);
    }
     */
    return 1;
}
int D_Delete(Table *ptab){
    /*
    char* k2=NULL;
    int rc,k1;
    int l;
    printf("Enter key1: -->");
    Get_Int(&k1);
    printf("Enter key2: -->");
    k2=Get_Strk2(ptab);
    if(k2==NULL)
        return 0;
    rc=delete(ptab,k1,k2);
    if(rc==0) printf("There is not such key.");
    if(rc==1) printf("Successfull deletion.\n");
    */
    return 1;
}


int D_Show(Table*ptab){
    for(int i=0;i<ptab->msize1;i++) {
        if (ptab->ks1[i].key != 0) {
            int a=ptab->ks1[i].key;
            int b=ptab->ks1[i].par;
            char *c= ptab->ks1[i].info->key2;
            char* d=ptab->ks1[i].info->inf;
            int e=ptab->ks1[i].info->realise;
            printf("key1: %d | parkey:%d |key2: %s | info: %s | realise: %d\n", ptab->ks1[i].key, ptab->ks1[i].par, ptab->ks1[i].info->key2, ptab->ks1[i].info->inf, ptab->ks1[i].info->realise);
        }
    }
    return 1;
}

int D_ParFind(Table *ptab){
    /*
    int l;
    int park;
    Item* rc=NULL;
    printf("Enter parkey: -->");
    Get_Int(&park);

    int i=0;
    rc=findkpar(ptab, park, i);
    if(rc==NULL){
        printf("There is not such key.");
        return 1;
    }
    else{
        printf("key1: %d | key2: %s | info: %s | realise: %d\n",rc->key1,rc->key2,rc->inf,rc->realise);
        while (rc!=NULL){
            rc=findkpar(ptab, park, i);
            printf("key1: %d | key2: %s | info: %s | realise: %d\n",rc->key1,rc->key2,rc->inf,rc->realise);
        }
    }
     */
    return 1;
}

