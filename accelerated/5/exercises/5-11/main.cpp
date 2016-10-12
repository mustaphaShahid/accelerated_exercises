#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::vector;
using std::max;

bool hasAscender(const string&);
bool hasDescender(const string&);

int main(int argc, char *argv[])
{
        string word;
        string line;
        string::size_type maxlen = 0;
        string::size_type prevMaxlen = 0;
        ifstream myfile("words.txt");
        while (getline(myfile, line))
                if (line != "" && !hasAscender(line) && !hasDescender(line)) {
                        maxlen = max(maxlen, line.size());
                        if (prevMaxlen != maxlen) {
                                word = line;
                                prevMaxlen = maxlen;
                        }
                }

        cout << word << endl;

        return 0;
}

bool hasAscender(const string& s)
{
        char c[] = {'b', 'd', 'f', 'h', 'k', 'l', 't'};
        for (string::const_iterator iter=s.begin(); iter!=s.end(); iter++)
                for (int i=0; i<7; i++)
                        if (*iter == c[i])
                                return true;
        return false;
}

bool hasDescender(const string& s)
{
        char c[] = {'g', 'j', 'p', 'q', 'y'};
        for (string::const_iterator iter=s.begin(); iter!=s.end(); iter++)
                for (int i=0; i<5; i++)
                        if (*iter == c[i])
                                return true;
        return false;
}
