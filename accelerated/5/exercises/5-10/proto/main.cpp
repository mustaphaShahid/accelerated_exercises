#include <iostream>

using std::cout;
using std::endl;
using std::string;

bool ispalindrome(const string&);

int main(int argc, char *argv[])
{
        string s = "radarradarradar";
        cout << ispalindrome(s) << endl;


        return 0;
}

bool ispalindrome(const string& s)
{
        for (string::size_type i=0; i<s.size()/2+1; i++) {
                if (!(s[i] == s[s.size()-i-1]))
                        return false;
        }
        return true;
}
