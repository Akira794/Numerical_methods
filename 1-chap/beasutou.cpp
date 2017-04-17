#include <iostream>
#include <cmath>
using namespace std;

#define EPS .0001

void bairstow( double* , double* , double[], int);
void root(double, double);

int main(int argc, char* argv[])
{
	int n = 4;
	double a[] = { 1, -2, 2, -50, 62};
	double p, q;
	
	cout << "Real" << "\t\t" << "Imaginary" << "\n";
	
	while( 1 ){
		if( n == 1 ){
			cout << -a[1]/a[0] << "\t\t" << 0.0 << "\n" << endl;
			return 0;
		}
		
		if( n == 2 ){
			root( a[1], a[2] );
			return 0;
		}

		if( n == 0 ) return 0;

		bairstow( &p, &q, a, n);
		root( p, q);
		n -= 2;
	}
}

void bairstow(double* p, double* q, double a[], int n)
{
	double b[n + 1], c[n + 1];
	double dp, dq, e;
	int k, i;
	
	*p = 1.0; //init Secondary factor
	*q = 1.0;
	
	do{
		b[0] = a[0];
		b[1] = a[1] - (*p) * b[0];
	
		for(k = 2; k <= n; k++){
			b[k] = a[k] - (*p) * b[k-1] - (*p) * b[k - 2];
		}

		c[0] = b[0];
		c[1] = b[1] - (*p) * c[0];
		for(k = 2; k <= n; k++){
			c[k] = b[k] - (*p) * c[k-1] - (*p) * c[k-2];
		}
		
		e = c[n-2] * c[n-2] - c[n-3] * ( c[n-1] - b[n-1] );
		
		dp = ( b[n-1] * c[n-2] - b[n ] * c[n-3] ) / e;
		
		dq = ( b[n ]  * c[n-2] - b[n-1] * ( c[n-1] - b[n-1] ) ) / e;
		
		*p += dp;
		*q += dq;
	
	}while( (fabs(dp) > EPS ) && (fabs(dq) > EPS ) );

	for(i = 0; i <= n-2; i++){
		a[i] = b[i];
	}
}

void root(double p, double q)
{
	double d, f;
	double r1, r2, i1, i2;
	d = p * p - 4.0 * q;

	if( d <= 0) {
		f = sqrt(-d);
		r1 = -p / 2.0;
		r2 = -p / 2.0;
		i1 = f / 2.0;
		i2 = -f / 2.0;

	}else{
		
		f = sqrt(d);
		r1 = (-p + f) / 2.0;
		r2 = (-p - f) / 2.0;
		i1 = 0.0;
		i2 = 0.0;
	}
	
	cout << r1 <<" \t"<< i1 <<"\n"<< r2 <<" \t"<< i2 << "\n" << endl;
}

