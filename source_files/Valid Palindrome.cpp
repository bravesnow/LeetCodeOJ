#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
bool isPalindrome(string s)
{//回文判断
    int i_front = 0, i_rear = s.size() - 1;//首尾标记点
    while (i_front < i_rear){
	//当 首索引值小于尾索引值
	while (!isalnum(s[i_front]) && i_front < i_rear){
	    ++i_front;//寻找数字或者字母，可能找不到
	}
	while (!isalnum(s[i_rear]) && i_front < i_rear){
	    --i_rear;//寻找数字或者字母，可能找不到
	}
	if (tolower(s[i_front])== tolower(s[i_rear])){
	    //当字母或者数字相同时候，索引移动，可能是回文
	    ++i_front;
	    --i_rear;	    
	}
	else 
	    return false;
    }
    return true;
}
int main(int argc, char *argv[])
{
    string s("A man, a plan, a canal: Panama");
    string ss("race a car");
    string sss(".,");
    if (isPalindrome(sss)){
	cout<<"yes"<<endl;
    }
    else
	cout<<"no"<<endl;
    return 0;
}
