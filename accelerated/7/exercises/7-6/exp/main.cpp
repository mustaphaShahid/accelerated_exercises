#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

vector<string> split(const string&);
bool space(char);
bool not_space(char);

int main(int argc, char *argv[])
{
        vector<string> loaded = split("testing yo");
        vector<string> unwound = split("another solid");

        return 0;
}

vector<string> split(const string& str)
{
        typedef string::const_iterator iter;
        vector<string> ret;

        iter i = str.begin();
        while (i != str.end()) {

                // ignore leading blanks
                i = find_if(i, str.end(), not_space);

                // find end of next word
                iter j = find_if(i, str.end(), space);

                // copy the characters i [i, j)
                if (i != str.end())
                        ret.push_back(string(i, j));
                i = j;
        }
        return ret;
}

bool space(char c)
{
        return isspace(c);
}

bool not_space(char c)
{
        return !isspace(c);
}
