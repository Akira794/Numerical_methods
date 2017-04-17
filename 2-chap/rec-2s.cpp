/* Gauss-Seidel method */

#include <iostream>
#include <cmath>
using namespace std;

#define N 5
#define EPS .0001
#define MAX_LOOP 50

int main(int argc, char* argv[])
{
	double a[N][N+1] = {

                {-2, 1, 0, 0, 0, 1},
                { 1,-2, 1, 0, 0, 2},
                { 0, 1,-2, 1, 0, 3},
                { 0, 0, 1,-2, 1, 4},
                { 0, 0, 0, 1,-2, 5},

	};

	double x[N], y[N], s, q;
	int i, j, k;

	for(i = 0; i < N; i++)
		x[i] = 1.0;

	for(k = 0; k < MAX_LOOP; k++){
		q = 0.0;
		for(i = 0; i < N; i++){
			s = 0.0;
			for(j = 0; j < N; j++)
				if(i != j)
					s += a[i][j] * x[j];

			y[i] = ( a[i][N] - s ) / a[i][i];
			q += fabs( x[i] - y[i] );
			x[i] = y[i];
		}
		if( q < EPS) {
			for(i = 0; i < N; i++)
				cout << "x" << i << "= " << x[i] << "\n";
			return 0;
		}
	}
	cout << "収束せず\n";
	return 1;
}

