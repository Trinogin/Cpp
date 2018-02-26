#include<iostream>
#include<fstream>
#include<cmath>
#include"EcuatHeader.h"
#include<vld.h>

using namespace std;

double EcuatDisc(double a, double b, double c)
{
	double result;

	result = b*b - 4.0 * a*c;
	return result;
}

void EcuatSolver(solve* mySolve, double a, double b, double c)
{
	double discriminant;

	if (a == 0.0)
	{
		if (b == 0.0)
		{
			if (c == 0.0)
			{
				mySolve->num = 3;
				return;
			}
			mySolve->num = 0;
			return;
		}
		*mySolve->root_1 = -c / b;
		mySolve->num = 1;
		return;
	}
	discriminant = EcuatDisc(a, b, c);
	if (discriminant < 0.0)
	{
		mySolve->num = -1;
		return;
	}
	if (discriminant == 0.0)
	{
		*mySolve->root_1 = -b / (2.0 * a);
		mySolve->num = 1;
		return;
	}
	*mySolve->root_1 = (-b + sqrt(discriminant)) / (2.0 * a);
	*mySolve->root_2 = (-b - sqrt(discriminant)) / (2.0 * a);
	mySolve->num = 2;
}

void EcuatSolvePrint(solve* mySolve)
{
	switch (mySolve->num)
	{
	case -1:
		cout << "No roots in real number" << endl;
		break;
	case 0:
		cout << "No root" << endl;
		break;
	case 1:
		cout << "One root, it is " << *mySolve->root_1 << endl;
		break;
	case 2:
		cout << "Two roots, first is " << *mySolve->root_1 << ", the second is " << *mySolve->root_2 << endl;
		break;
	case 3:
		cout << "Root is any number" << endl;
		break;
	}
}

int main(void)
{
	double a, b, c;
	solve mySolve;

	mySolve.root_1 = (double*)malloc(sizeof(double));
	if (mySolve.root_1 == NULL)
	{
		cout << "Error: not enough memory" << endl;
		return -1;
	}

	mySolve.root_2 = (double*)malloc(sizeof(double));
	if (mySolve.root_2 == NULL)
	{
		free(mySolve.root_1);
		cout << "Error: not enough memory" << endl;
		return -1;
	}

	cout << "Input coefficients of quad ecuation: ";
	cin >> a >> b >> c;

	EcuatSolver(&mySolve, a, b, c);

	EcuatSolvePrint(&mySolve);
	free(mySolve.root_1);
	free(mySolve.root_2);
	return 0;
}