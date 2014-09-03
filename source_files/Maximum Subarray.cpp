#include <iostream>
#include <algorithm>
using namespace std;  
int maxSubArray(int A[], int n)
{//�����������
    //��ÿһ��Ԫ������״̬��fstate[i]ָ������A[i]��β�����������ֵ
    //��Ȼ����������������
    int *fstate = new int[n];
    for (int i = 0; i < n; ++i){
	fstate[i] = A[i];
    }
    for (int i = 1; i < n; ++i){
	fstate[i] = max(fstate[i-1] + A[i], A[i]);
    }
    int maxSum = *max_element(fstate, fstate + n);
    delete []fstate;
    return maxSum;
}
int maxSubArray_opt(int A[], int n)
{//����������С����Ż���
    //maxSum�����������кͣ�curSum�ǵ�ǰ�����еĺ�
    int maxSum(A[0]), curSum(A[0]);
    for (int i = 1; i < n; ++i){
        curSum = max(curSum + A[i], A[i]);
	if (maxSum < curSum){
	    maxSum = curSum;
	}
    }
    return maxSum;
}
int main(int argc, char *argv[])
{
    int array[] = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    cout<<maxSubArray_opt(array, sizeof(array)/sizeof(int));
    return 0;
}
