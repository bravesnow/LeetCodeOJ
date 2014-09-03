#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minimumTotal(vector<vector<int> > &triangle)
{//从上到下，对每一个位置，求得路径最小和，存储到state
    vector<vector<int> > state(triangle);
    int rows = triangle.size();
    for (int i = 1; i < rows; ++i){
	int cols = triangle[i].size();
	for (int j = 0; j < cols; ++j){
	    //根据j的三种值，有三种选择
	    if (j == 0){
		state[i][j] = state[i-1][j] + triangle[i][j];
	    }
	    else if (j == cols - 1){
		state[i][j] = state[i-1][j-1] + triangle[i][j];
	    }
	    else {
		state[i][j] = min(state[i-1][j-1], state[i-1][j]) + triangle[i][j];
	    }
	}
    }
    //返回的是最后一个vector中最小的值
    return *min_element(state[rows-1].begin(), state[rows-1].end());
}
int main(int argc, char *argv[])
{
    vector<vector<int> > tri;
    vector<int> x;
    x.push_back(2);
    tri.push_back(x);
   
    int tempa[] = {3,4};
    vector<int> xa(tempa, tempa+2);
    tri.push_back(xa);

    int tempb[] = {6,5,7};
    vector<int> xb(tempb, tempb+3);
    tri.push_back(xb);

    int tempc[] = {4,1,8,3};
    vector<int> xc(tempc, tempc+4);
    tri.push_back(xc);
    
    cout<<minimumTotal(tri)<<endl;
    return 0;
}
