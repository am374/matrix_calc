#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#include "matrix.h"

/*****************************************************/
/*                                                   */
/*  Andrew's Matrix Calculator                       */
/*  Ver 0.1                                          */
/*****************************************************/




void welcome();
void getmatrix(double matrixIn [ARRAYMAX] [ARRAYMAX], int& m, int& n, char name);
void printmatrix(double matrixIn [ARRAYMAX] [ARRAYMAX], int m, int n, char name);
void intitarray(double matrixIn [ARRAYMAX] [ARRAYMAX], int m, int n);
bool ref(double matrixIn [ARRAYMAX] [ARRAYMAX], int m, int n);
bool rref(double matrixIn [ARRAYMAX] [ARRAYMAX], int m, int n);
void rowswap(double matrixIn [ARRAYMAX] [ARRAYMAX], int i1, int i2, int n);
void copymatrix(double matrixIn [ARRAYMAX] [ARRAYMAX], double matrixOut [ARRAYMAX] [ARRAYMAX], int m, int n);
