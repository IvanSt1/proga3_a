//
// Created by ivan on 11.04.2021.
//

#ifndef PROGA3_A_ITEM_H
#define PROGA3_A_ITEM_H


typedef struct Item {
    char *inf;
    int key1;
    char *key2;
    int realise;
    struct KeySpace2 *ks2;
    struct KeySpace1 *ks1;
} Item;
typedef struct KeySpace1 {
    int key;
    int par;
    Item *info;
} KeySpace1;
typedef struct KeySpace2 {
    char *key;
    Item *info;
    int realise;
    struct KeySpace2 *next;
    struct KeySpace2 *previous;
} KeySpace2;
#endif //PROGA3_A_ITEM_H
