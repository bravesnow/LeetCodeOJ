#include <iostream>
using namespace std;
int removeElement(int A[], int n, int elem) {
    //���ǱȽϣ�һ�鼴��
    int index = 0;
    for (int i = 0; i < n; ++i){
	if (A[i] != elem){
	    A[index++] = A[i];
	}
    }
    return index;
}
int main(int argc, char *argv[])
{
    int a[] = {3, 8, 3, 2, 9};
    cout<<removeElement(a, 5, 3)<<endl;
    return 0;
}
