#ifndef _OUTIL3_H_
#define _OUTIL3_H_
#define OPTION_T "-t"
#define OPTION_D "-d"
#define OPTION_S "-s"
#define OPTION_I "-i"

#include "malib.h"

int cmd(int, char**);

void printOptions(int, transactions_t*, temp_t*);

float distanceMetres(int, int);

#endif
