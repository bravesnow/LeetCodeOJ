#include <iostream>
using namespace std;
int find_kth(int A[], int m, int B[], int n, int k);
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int k = (m+n)/2;
    if ((m+n)%2) {
	return (double)find_kth(A, m, B, n, k+1);
    }
    else {
	cout<<k<<"he"<<endl;
	return (double)(find_kth(A, m, B, n, k) +
			find_kth(A, m, B, n, k+1))/2;
    }
}
int find_kth(int A[], int m, int B[], int n, int k)
{//find the top k
    if (m > n) {
	return find_kth(B, n, A, m, k);
    }
    if (m == 0) {
	return B[k-1];
    }
    if (k == 1) {
	return A[0] < B[0] ? A[0] : B[0];
    }
    int ia = k/2 < m ? k/2 : m;
    int ib = k - ia;
    if (A[ia-1] < B[ib-1]) {
	return find_kth(A+ia, m-ia, B, n, k-ia);
    }
    else if (A[ia-1] > B[ia-1]){
	return find_kth(A, m, B+ib, n-ib, k-ib);
    }
    else {
	return A[ia-1];
    }
}
int main(int argc, char *argv[])
{
    int a[] = {1,4,6,9};
    int b[] = {2,8};
    cout<<findMedianSortedArrays(a,4,b,2)<<endl;
    return 0;
}
