#ifndef _ECUAT_HEADER_INCLUDED
#define _ECUAT_HEADER_INCLUDED

#pragma once

struct solve
{
	int num;
	double* root_1;
	double* root_2;
};

double EcuatDisc(double a, double b, double c);

void EcuatSolver(solve* mySolve, double a, double b, double c);

void EcuatSolvePrint(solve* mySolve);

#endif //_ECUAT_HEADER_INCLUDED