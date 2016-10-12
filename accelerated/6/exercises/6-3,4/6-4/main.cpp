#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::copy;
using std::back_inserter;

int main(int argc, char *argv[])
{
        vector<int> u(10000000, 100);        
        vector<int> v;
        copy(u.begin(), u.end(), back_inserter(v));
        /*
         * for (vector<int>::const_iterator iter=v.begin(); iter!=v.end(); iter++)
         *         cout << *iter << endl;
         */
        return 0;
}
