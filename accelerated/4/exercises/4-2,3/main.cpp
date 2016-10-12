#include <iostream>
#include <iomanip>
#include <math.h>

using std::cout;
using std::endl;
using std::string;
using std::setw;

int main(int argc, char *argv[])
{
        int max = 999;
        int maxlen = log10(max * max) + 1;
        for (int i=1; i<max+1; i++)
                cout << i << setw(maxlen + 1) << i * i << endl;

        return 0;
}
