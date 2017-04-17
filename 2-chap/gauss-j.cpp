/* Gauss - Jordan elimination */

#include <iostream>
#include <cmath>
using namespace std;

#define N 3
#define EPS .001

int main( int argc, char *argv[])
{
	double a[N][N+1] = {
		{2, 1, 3, 13},
		{1, 3, 2, 13},
		{3, 2, 1, 10}
	};
	double pivot, del;
	int i, j ,k , l;
	
	for(i = 0; i < N; i++){
		pivot = a[i][i];
//		cout << "pivot =  " << pivot;
		if( fabs(pivot) < EPS ){
			cout << "ピボットが許容誤差以下\n";
			return 1;
		}
		//pivot = 1
		for(j = i; j < N+1; j++){
			a[i][j] = a[i][j] / pivot;
//			cout << "p[" <<i << "][" << j << "]= "<< a[i][j] <<"\t";
		}

		for(k = 0; k < N; k++){
			del = a[k][i];
//			cout << "del: "<< del << " k:i" << k <<":" << i <<  "\t";
			for(j = i; j < N+1; j++){
				if(k != i)
					a[k][j] -= del * a[i][j];
//					cout << "a["<< k << "][" << j << "] = " << a[k][j] << "\t";
			}
		}
	}

	for(l = 0; l < N; l++){
		cout <<"X"<< l <<"= "<<  a[l][N] << endl;
	}
	return 0;
}

	
