//
// Created by ivan on 11.04.2021.
//

#ifndef PROGA3_A_DIALOG_H
#define PROGA3_A_DIALOG_H

#include "table.h"

int dialog(const char *msgs[], int n);

int D_Find(Table *ptab);

int D_Add(Table *ptab);

int D_Delete(Table *ptab);

int D_ParFind(Table *ptab);

int D_Show(Table *ptab);

int D_Find_Realises(Table *ptab);

int D_Find_Curent_Realise(Table *ptab);

int D_Findk1(Table *ptab);

int D_Reorg(Table *ptab);

#endif //PROGA3_A_DIALOG_H
