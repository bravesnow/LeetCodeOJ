#include <iostream>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    string::size_type i(0), n(s.size()), maxlen(0);
    string curr;
    for (i = 0; i < n; ++i) {
	string::size_type pos = curr.find_last_of(s[i]);
	curr.push_back(s[i]);	
	if (pos != s.npos) {
	    maxlen = max(maxlen, curr.size()-1);
	    curr = curr.substr(pos+1);
	}
    }
    maxlen = max(maxlen, curr.size());//!!!!!!
    return maxlen;
}
int main(int argc, char *argv[])
{
    string s = "qopubjguxhxdipfzwswybgfylqvjzhar";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
