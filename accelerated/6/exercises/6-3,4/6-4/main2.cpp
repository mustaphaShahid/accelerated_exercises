#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char *argv[])
{
        vector<int> u(10000000, 100);
        vector<int> v(u.size(), 0);
        copy(u.begin(), u.end(), v.begin());
        /*
         * for (int i=0; i<v.size(); i++)
         *         cout << v[i] << endl;
         */
        return 0;
}
