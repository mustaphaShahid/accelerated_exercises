#include <algorithm>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::find_if;
using std::find;

bool space(char);

int main(int argc, char *argv[])
{
        string str = "hello peeps";
        string str2 = "hellopeeps";
        string &rStr = str;
        string::iterator i = rStr.begin();
        if ((i = find_if(i, rStr.end(), isspace)) != rStr.end())
                cout << "contains space" << endl;
        else
                cout << "no spaces" << endl;
        return 0;
}

bool space(char c)
{
        return isspace(c);
}
