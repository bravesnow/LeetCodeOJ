#include <iostream>
using namespace std;
int reverse(int x) {
        int r = 0;
        for(;x;x/=10){
            r = r*10+x%10;
        }
        return r;
}
int main(int argc, char *argv[])
{
    int a = 2345;
    cout<<reverse(a)<<endl;
    return 0;
}
