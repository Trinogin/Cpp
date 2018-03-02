#include<iostream>
#include<vld.h>
#include"EcuatHeader.h"

using namespace std;

int main(void)
{
	double a, b, c;
	solve* mySolve = NULL;

	mySolve = solveInit(mySolve);
	if (mySolve == NULL)
	{
		cout << "Error: not enough memory" << endl;
		return -1;
	}

	cout << "Input coefficients of quad ecuation: ";
	cin >> a >> b >> c;

	EcuatSolver(a, b, c, mySolve);
	EcuatSolvePrint(mySolve);

	solveDelete(mySolve);
	return 0;
}