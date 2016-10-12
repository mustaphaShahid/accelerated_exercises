#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::copy;

int main(int argc, char *argv[])
{
        vector<int> u(10, 100);
        vector<int> v;
        copy(u.begin(), u.end(), v.begin());
        return 0;
}
