#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
int maxPoints(vector<Point> &points) {
    if (points.size() < 3)
	return points.size();
    int result = 0;
    map<double, int> slope_count;
    vector<Point>::iterator iter,jter;
    for (iter = points.begin(); iter != points.end()-1; iter++) {
	slope_count.clear();
	int samePointNum = 0; // 与 i 重合的点
	int point_max = 1; // 和 i 共线的最大点数	
	for (jter = iter + 1; jter != points.end(); jter++) {
	    double slope; // 斜率
	    if ((*iter).x == (*jter).x) {
		slope = std::numeric_limits<double>::infinity();
		if ((*iter).y == (*jter).y) {
		    ++ samePointNum;
		    continue;
		}
	    }
	    else {
		slope = 1.0 * ((*iter).y - (*jter).y) /
		    ((*iter).x - (*jter).x);
	    }
	    int count = 0;
	    if (slope_count.find(slope) != slope_count.end())
		count = ++slope_count[slope];
	    else {
		count = 2;
		slope_count[slope] = 2;
	    }
	    if (point_max < count) point_max = count;
	}
	result = max(result, point_max + samePointNum);
    }
    return result;
}
int main(int argc, char *argv[])
{
    Point p1(0,0),p2(1,1),p3(0,0);
    
    return 0;
}
