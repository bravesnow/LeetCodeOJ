#include <iostream>
using namespace std;
inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline int min(int a, int b)
{
    return a < b ? a : b;
}
int maxProduct(int A[], int n)
{
    int maxP = A[0];
    int curmaxP = A[0], curminP = A[0];
    for (int i = 1; i < n; ++i) {
	int temp_curmaxP = max( max(curmaxP*A[i], curminP*A[i]), A[i] );
	curminP = min( min(curmaxP*A[i], curminP*A[i]), A[i] );
	curmaxP = temp_curmaxP;
	maxP = max(curmaxP, maxP);
    }
    return maxP;
}

int main(int argc, char *argv[])
{
    int A[] = {-2, -3, +2, -4};
    cout<<maxProduct(A, 4)<<endl;
    return 0;
}
