#pragma once

const int ARRAYMAX = 50;
struct MATRIX {
double mat[ARRAYMAX] [ARRAYMAX]; // matrix
int m = 0;                       // number of rows
int n = 0;                       //number of columns
char name;                   // matrix name
bool inRef = false;                //is matrix in ref form?
};

