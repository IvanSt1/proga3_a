#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "keyspace1.h"
#include "keyspace2.h"
#include "item.h"

int Get_Int(int* a){
    int n=0;
    while (n==0){
        n = scanf("%d", a);
        if (n==0 || *a<0){
            printf("Error reading positive integer value\n");
            scanf("%*[^\n]");
            n=0;
        }
    }
    return n < 0 ? 0 : 1;
}

char *Get_Str(){
    int  len=0,n;
    char buf[80];
    char *res = malloc(80 * sizeof(char));
    *res = '\0';
    scanf("%*[\n]");
    do {
        n = scanf("%79[^\n]", buf);
        len += strlen(buf);
        if (n > 0) {
            res = realloc(res, len * sizeof(char)+1);
            strcat(res, buf);
        }
    } while ( n != 0 && n != -1);
    if (n == -1) {
        free(res);
        return NULL;
    }
    return res;
}
char *Get_Strk2(){
    int  len=0,n;
    char *res = malloc((maxstrinsize+1) * sizeof(char));
    *res = '\0';
    scanf("%*[\n]");
    do {
        n = scanf("%10[^\n]", res);
    } while ( n != 0 && n != -1);
    if (n == -1) {
        free(res);
        return NULL;
    }
    return res;
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
    }while(rc<0 || rc>=n);
    return rc;
}

int D_Find(Table*ptab){
    int l;
    int k1;
    char* k2=NULL;
    Item* rc=NULL;
    printf("Enter key1: -->");
    Get_Int(&k1);
    printf("Enter key2: -->");
    k2=Get_Strk2();

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
    return 1;
}
int D_Find_All_Versions(Table *ptab){
    int l;
    int k1,i;
    char* k2=NULL;
    KeySpace2 rc;
    printf("Enter key2: -->");
    k2=Get_Strk2();
    if(k2==NULL)
        return 0;
    i=findk2_fromBegin(ptab,k2);
    if(i==ptab->csize){
        printf("There is not such key.");
        return 1;
    }
    else{
        rc=ptab->ks2[i];
        printf("key1: %d | key2: %s | info: %s | realise: %d\n",rc.key,rc.key,rc.info->inf,rc.realise);
        while (rc.next!=NULL){
            rc=*rc.next;
            printf("key1: %d | key2: %s | info: %s | realise: %d\n",rc.key,rc.key,rc.info->inf,rc.realise);
        }
    }
    return 1;
}
const char *errmsgs[]={"OK","Duplicate key", "Table overflow"};
int D_Add(Table*ptab){
    int rc;
    int l;
    int k1;
    char* k2=NULL;
    char* info;
    printf("Enter key1: -->");
    Get_Int(&k1);
    printf("Enter key2: -->");
    k2=Get_Strk2();
    if(k2==NULL)
        return 0;
    printf("Enter info:\n");
    info=Get_Str();
    if(info==NULL)
        return 0;
    rc=insert(ptab,k1,k2,info);
    printf("%s: %d, %s\n",errmsgs[rc],k1,k2);
    return 1;
}

int D_Delete(Table *ptab){
    char* k2=NULL;
    int rc,k1;
    int l;
    printf("Enter key1: -->");
    Get_Int(&k1);
    printf("Enter key2: -->");
    k2=Get_Strk2();
    if(k2==NULL)
        return 0;
    rc=delete(ptab,k1,k2);
    if(rc==0) printf("There is not such key.");
    if(rc==1) printf("Successfull deletion.\n");
    return 1;
}


int D_Show(Table*ptab){
    for(int i=0;i<ptab->csize;++i){
        printf("key1: %d | parkey:%d |key2: %s | info: %s | realise: %d\n",ptab->ks1[i].key,ptab->ks1[i].par,ptab->ks2[i].key,ptab->ks1[i].info->inf,ptab->ks2[i].realise);
    }
    return 1;
}


