//
// Created by ivan on 11.04.2021.
//

#ifndef PROGA3_A_DIALOG_H
#define PROGA3_A_DIALOG_H

#include "table.h"

int Get_Int(int* a);
char *Get_Str();
char *Get_Strk2();
int dialog(const char *msgs[], int n);
int D_Find(Table*ptab);
int D_Add(Table*ptab);
int D_Delete(Table *ptab);
int D_ParFind(Table *ptab);
int D_Find_All_Versions(Table *ptab);
int D_Show(Table*ptab);
#endif //PROGA3_A_DIALOG_H
