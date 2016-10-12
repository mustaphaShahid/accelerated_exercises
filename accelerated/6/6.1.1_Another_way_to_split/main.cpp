#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;

bool space(char);
bool not_space(char);
vector<string> split(const string&);

int main(int argc, char *argv[])
{
        vector<string> v = split("greetings people of the earth"); 
        for (vector<string>::const_iterator iter=v.begin(); iter!=v.end(); iter++)
                cout << *iter << endl;
        return 0;
}

bool space(char c)
{
        return isspace(c);
}

bool not_space(char c)
{
        return !isspace(c);
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
