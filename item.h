//
// Created by ivan on 11.04.2021.
//

#ifndef PROGA3_A_ITEM_H
#define PROGA3_A_ITEM_H

#include "keyspace2.h"

typedef struct Item{
    char* inf;
    int key1;
    char* key2;
    int realise;
    struct KeySpace2 *ks2;
} Item;
#endif //PROGA3_A_ITEM_H
