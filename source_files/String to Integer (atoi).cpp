#include <iostream>
#include <climits>
using namespace std;
int atoi(const char *str) {
    int flag = 1;
    int rnum = 0;
    const char *c = str;
    while (*c == ' '){
	c++;
    }
    if(*c == '+'){
	flag = 1;
	c++;
    }
    else if(*c == '-'){
	flag = -1;
	c++;
    }
    while (*c!='\0'){
	cout<<*c<<endl;
	if (*c<'0' || *c>'9'){
	    cout<<*c<<endl;
	    break;
	}
	cout<<"hel"<<endl;
	if (rnum > INT_MAX / 10 ||(rnum == INT_MAX/10 &&(*c - '0') > INT_MAX%10)) {
	    return flag == -1 ? INT_MIN : INT_MAX;
	}
	rnum = rnum*10 + *c - '0';	
	c++;
    }
    return flag*rnum;
}
int main(int argc, char *argv[])
{
    const char* s = "+-2";
    cout<<atoi(s)<<endl;
    return 0;
}

