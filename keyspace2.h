//
// Created by ivan on 11.04.2021.
//

#ifndef PROGA3_A_KEYSPACE2_H
#define PROGA3_A_KEYSPACE2_H
#include "item.h"
#define maxstrinsize 10
typedef struct KeySpace2{
    char* key;
    Item *info;
    int  realise;
    struct KeySpace2 * next;
} KeySpace2;
#endif //PROGA3_A_KEYSPACE2_H
