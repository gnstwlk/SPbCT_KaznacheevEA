#include "pch.h"
#include "MathFuncsDll.h"
#include <stdexcept>
using namespace std;
namespace MathFuncs
{
	double MyMathFuncs::Add(double a, double b)
	{
		return a + b;
	}
	double MyMathFuncs::Subtract(double a, double b)
	{
		return a - b;
	}
	double MyMathFuncs::Multiply(double a, double b)
	{
		return a * b;
	}
	double MyMathFuncs::Divide(double a, double b)
	{
		if (b == 0)
		{
			throw invalid_argument("b cannot be zero!");
		}
		return a / b;
	}
	double MyMathFuncs::Pow(double a, int b)
	{
		for (int i = 0; i < b - 1; i++)
			a *= a;
		if (b == 0)
			return 1;
		else
			return a;
	}
}
