#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::search;
using std::string;

int main(int argc, char *argv[])
{
        string str = "hello master baggins, may i take your bag"; 
        const static string name = "master bagins";
        typedef string::iterator iter;
        if (search(str.begin(), str.end(), name.begin(), name.end()) != str.end())
                cout << "found string" << endl;
        else
                cout << "string not found" << endl;
        return 0;
}
