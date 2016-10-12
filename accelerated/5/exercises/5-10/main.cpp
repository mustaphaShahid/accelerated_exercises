#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::getline;
using std::max;

bool ispalindrome(const string&);

int main(int argc, char *argv[])
{
        vector<string> dict;
        string line;

        ifstream myfile("words.txt");
        while (getline(myfile, line))
                dict.push_back(line);

        string::size_type maxlen = 0;
        for (vector<string>::const_iterator iter=dict.begin(); iter!=dict.end(); iter++)
                if (ispalindrome(*iter)) {
                        cout << *iter << endl;
                        maxlen = max(maxlen, iter->size());
                }

        cout << endl << "largest palindrome size: " << maxlen;

        return 0;
}

bool ispalindrome(const string& s)
{
        if (s == "") return false;
        for (string::size_type i=0; i<s.size()/2+1; i++) {
                if (!(s[i] == s[s.size()-i-1]))
                        return false;
        }
        return true;
}
