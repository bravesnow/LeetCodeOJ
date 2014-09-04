#include <iostream>
using namespace std;
double pow(double x, int n) {
    if (n == 0){//0次方为1
	return 1;
    }
    if (n == 1){//1次方
	return x;
    }
    if (n == -1){//-1次方
	return 1/x;
    }
    double t = pow(x, n/2);//
    return t*t*pow(x, n%2);
}
int main(int argc, char *argv[])
{
    cout<<pow(2, -3)<<endl;
    cout<<pow(3, 5)<<endl;
    return 0;
}
