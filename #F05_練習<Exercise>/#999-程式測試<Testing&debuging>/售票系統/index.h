#include "Global.h"

#ifndef INDEX_H
#define INDE2X_H

#define seatNumber char seat[12][16]

void menu();
void Func(seatNumber, int request);
void Empt(seatNumber);
void Output(seatNumber);
void select_Seat(seatNumber, int x, int y);

#endif