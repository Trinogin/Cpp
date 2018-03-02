#include"EcuatHeader.h"

solve* solveInit(solve* mySolve)
{
	mySolve = (solve*)malloc(sizeof(solve));
	if (mySolve == NULL)
		return NULL;

	mySolve->root_1 = (double*)malloc(sizeof(double));
	if (mySolve->root_1 == NULL)
	{
		free(mySolve);
		return NULL;
	}

	mySolve->root_2 = (double*)malloc(sizeof(double));
	if (mySolve->root_2 == NULL)
	{
		free(mySolve->root_1);
		free(mySolve);
		return NULL;
	}

	return mySolve;
}

void solveDelete(solve* mySolve)
{
	if (mySolve != NULL)
	{
		if (mySolve->root_1 != NULL)
			free(mySolve->root_1);
		if (mySolve->root_2 != NULL)
			free(mySolve->root_2);
		free(mySolve);
	}
}

double EcuatDisc(double a, double b, double c)
{
	double result;

	result = b*b - 4.0 * a*c;
	return result;
}

void EcuatSolver(double a, double b, double c, solve* mySolve)
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