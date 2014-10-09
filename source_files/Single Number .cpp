#include <iostream>
using namespace std; 
int singleNumber(int A[], int n)
{
    int x = 0;
    for (int i = 0; i < n; ++i) {
	x ^= A[i];
    }
    return x;
	 
}
int main(int argc, char *argv[])
{
    int a[] = {2,3,4,3,2};
    cout<<singleNumber(a, 5)<<endl;
    return 0;
}
