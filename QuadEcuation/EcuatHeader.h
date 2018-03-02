#ifndef _ECUAT_HEADER_INCLUDED
#define _ECUAT_HEADER_INCLUDED

#pragma once

#include<iostream>
#include<fstream>

using namespace std;

typedef struct solve
{
	int num;
	double* root_1;
	double* root_2;
}solve;

solve* solveInit(solve* mySolve);

void solveDelete(solve* mySolve);

double EcuatDisc(double a, double b, double c);

void EcuatSolver(double a, double b, double c, solve* mySolve);

void EcuatSolvePrint(solve* mySolve);

#endif //_ECUAT_HEADER_INCLUDED