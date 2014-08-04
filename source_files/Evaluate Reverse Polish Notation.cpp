#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;
int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    int x,y;
    for (vector<string>::iterator iter = tokens.begin(); iter!=tokens.end(); ++iter){
	
	if(*iter == "+"){
	    x = s.top();s.pop();
	    y = s.top();s.pop();
	    s.push(x+y);
	}
	else if(*iter == "-"){
	    x = s.top();s.pop();
	    y = s.top();s.pop();
	    s.push(x-y);
	}
	else if(*iter == "*"){
	    x = s.top();s.pop();
	    y = s.top();s.pop();
	    s.push(x*y);
	}
	else if(*iter == "/"){
	    x = s.top();s.pop();
	    y = s.top();s.pop();
	    s.push(x/y);
	}
	else{
	    int i;
       	    s.push(atoi((*iter).c_str()));
	}
	
    }
    return s.top();
}
int main(int argc, char *argv[])
{
    string a[3] = {"0","3","/"};
    vector<string> tk(a,a+3);
    cout<<evalRPN(tk)<<endl;
    return 0;
}

