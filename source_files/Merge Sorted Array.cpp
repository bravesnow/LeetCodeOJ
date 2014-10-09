#include <iostream>
using namespace std; 
void merge(int A[], int m, int B[], int n)
{
    int ia(m-1), ib(n-1), ir(m+n-1);
    while (ia >= 0 && ib >= 0) {
	A[ir--] = A[ia] > B[ib] ? A[ia--] : B[ib--];
    }
    while (ib >= 0) {
	A[ir--] = B[ib--];
    }
}
int main(int argc, char *argv[])
{
    int a[7] = { 3, 6, 9, 11};
    int b[] = { 1, 4, 5};
    merge(a, 4, b, 3);
    for (int i = 0; i < 7; ++i) {
	cout<<a[i]<<endl;
    }
    return 0;
}
