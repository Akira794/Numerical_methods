/* 2分法　*/

#include <iostream>
#include <cmath>

using namespace std;
#define EPS .0001

double dichotomy(double, double);
double func_y(double);

int main(int argc, char* argv[])
{
	double a = 0.0, b = 1.0; //Initial value setting
	double x; //Solution
	
	cout << "x^3 + 2x - 4 = 0 の2分法による数値計算" << endl;
	
	cout << "初期値 a = " << a << endl;
	cout << "初期値 b = " << b << endl;
	
	x = dichotomy(a, b);
	cout << "近似解 x = " << x << endl;

	return 0;
}

double dichotomy(double a, double b)
{
	double c;
	
	do{
		c = (a + b) / 2.0; /* 2分計算 */
		
		if( (func_y(c) * func_y(a) ) < 0 ) b = c;

		else a = c;

	}while ( fabs(a - b) > EPS );

	return c;
}

double func_y(double x)
{
	return pow(x, 3.0) + (2.0 * x) - 4.0;
}
