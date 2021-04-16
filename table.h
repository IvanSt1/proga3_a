//
// Created by ivan on 11.04.2021.
//

#ifndef PROGA3_A_TABLE_H
#define PROGA3_A_TABLE_H
#include "keyspace2.h"
#include "keyspace1.h"
#include "item.h"
typedef struct Table{
    KeySpace1 *ks1;
    KeySpace2 *ks2;
    int msize;
    int csize;
} Table;
int insert(Table* ptab, int* k1, char *k2, char * info);
Item * find(Table *ptab,int k1, char *k2);
Item * findk1(Table *t,int k1);
int findk2(Table *t,char* k2);
Item * findkpar(Table *t,int kpar, int i);
int findk2_fromBegin(Table *t,char *k2);
int delete(Table *ptab, int k1, char *k2);
#endif //PROGA3_A_TABLE_H
