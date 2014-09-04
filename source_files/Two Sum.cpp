#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target)
{//map的查找速度更快
    vector<int> rt;//结果索引存储
    map<int, int> mapping;
    for (int i = 0; i < numbers.size(); ++i){
	mapping[numbers[i]] = i;//以值作为键，索引作为值
    }
    for (int i = 0; i < numbers.size(); ++i){
	int gap = target - numbers[i];
	if (mapping.find(gap) != mapping.end() && mapping[gap] > i){
	    //查找map，并且所得的索引要大于原始索引，这是为了防止，找到了相同的索引。
	    rt.push_back(i + 1);
	    rt.push_back(mapping[gap] + 1);
	    return rt;
	}
    }
    return rt;
}

int main(int argc, char *argv[])
{
    int a[] = {2, 7, 11, 15};
    vector<int> num(a, a + 4);
    int b = 18;
    vector<int> rt = twoSum(num, b);
    cout<<rt[0]<<rt[1]<<endl;
    return 0;
}
