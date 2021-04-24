#include"dialog.h"
#include <string.h>
#include "item.h"
#include "Get.h"
#include "table.h"
#include <stdlib.h>
#include <stdio.h>

Item *find(Table *t, int k1, char *k2) {
    int i;
    for (i = 0; i < t->msize1; i++) {
        if (t->ks1[i].key != 0) {
            if ((t->ks1[i].key == k1) && (strcmp(t->ks1[i].info->key2, k2) == 0)) {
                break;
            }
        }
    }

    if (i == t->msize1)
        return NULL;
    else
        return t->ks1[i].info;
}

Item *findk1(Table *t, int k1) {
    int i = 0;
    while ((i < t->msize1) && (t->ks1[i].key != k1)) {
        i++;
    }
    if (i == t->msize1)
        return NULL;
    else
        return t->ks1[i].info;
}

KeySpace1 *findkpar(Table *t, int kpar, int *kol) {
    KeySpace1 *ks1;
    *kol = 0;
    ks1 = (KeySpace1 *) calloc(sizeof(KeySpace1), (*kol + 1));
    for (int i = 0; i < t->msize1; i++) {
        if (t->ks1[i].key != 0) {
            if (t->ks1[i].par == kpar) {
                ks1 = realloc(ks1, sizeof(KeySpace1) * (*kol + 1));
                ks1[*kol] = t->ks1[i];
                (*kol)++;
            }
        }
    }
    if (*kol == 0) {
        free(ks1);
        return NULL;
    }
    else
        return ks1;
}


int insert(Table *t, int k1, int par, char *k2, char *information) {
    int h;
    if (findk1(t, k1) != NULL) return 1;
    else {
        if (t->msize1 == t->csize1) return 2;
        else {
            if ((findk1(t, par) == NULL) && (par != 0)) return 3;
            else {
                KeySpace2 *newks2= calloc(sizeof (KeySpace2*),1);
                Item *item = malloc(sizeof(Item));
                item->key1 = k1;
                item->key2 = k2;
                item->inf = information;
                h = Hesh(t, k2);
                if (t->ks2[h] == NULL) {

                    item->realise = 0;
                    newks2->realise=0;
                    newks2->key = k2;
                    newks2->next = NULL;
                    newks2->previous = NULL;
                    newks2->info = item;
                    t->ks2[h] = newks2;
                } else {
                    newks2->key = k2;
                    newks2->previous = NULL;
                    newks2->realise = t->ks2[h]->realise + 1;
                    item->realise = t->ks2[h]->realise + 1;
                    newks2->info = item;
                    t->ks2[h]->previous = newks2;
                    newks2->next = t->ks2[h];
                    t->ks2[h] = newks2;
                    item->ks2 = t->ks2[h];
                }
                for (int i = 0; i < t->msize1; i++) {
                    if (t->ks1[i].key == 0) {
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

int delete(Table *t, int k1, char *k2) {
    int i = 0;
    int h = Hesh(t, k2);
    for (int i = 0; i < t->msize1; i++) {
        if ((strcmp(t->ks1->info->key2, k2) == 0) && (t->ks1[i].key == k1))
            break;
    }
    if (i == t->msize1) {
        return 0;
    }
    Item *item;
    item = t->ks1[i].info;
    KeySpace2 *ks2;
    ks2 = item->ks2;
    ks2->previous->next = ks2->next;
    free(item);
    free(ks2);
    free(t->ks1[i].info->inf);
    free(t->ks1[i].info);
    t->ks1[i].key = 0;
    t->csize1 = t->csize1 - 1;
    for (int i = 0; i < t->msize1; i++) {
        if (t->ks1[i].key != 0) {
            if (t->ks1[i].par == k1)
                t->ks1[i].par = 0;
        }

    }
    return 1;

}