#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
bool isPalindrome(string s)
{//�����ж�
    int i_front = 0, i_rear = s.size() - 1;//��β��ǵ�
    while (i_front < i_rear){
	//�� ������ֵС��β����ֵ
	while (!isalnum(s[i_front]) && i_front < i_rear){
	    ++i_front;//Ѱ�����ֻ�����ĸ�������Ҳ���
	}
	while (!isalnum(s[i_rear]) && i_front < i_rear){
	    --i_rear;//Ѱ�����ֻ�����ĸ�������Ҳ���
	}
	if (tolower(s[i_front])== tolower(s[i_rear])){
	    //����ĸ����������ͬʱ�������ƶ��������ǻ���
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
