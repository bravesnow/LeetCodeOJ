#include <iostream>
#include <algorithm>
using namespace std;  
int maxSubArray(int A[], int n)
{//最长连续子序列
    //对每一个元素设置状态，fstate[i]指的是以A[i]结尾的子序列最大值
    //当然可以设置两个变量
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
{//最长连续子序列——优化版
    //maxSum是最大的子序列和，curSum是当前子序列的和
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
