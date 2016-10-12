#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include <time.h>

using std::domain_error;
using std::cout;
using std::endl;
using std::numeric_limits;

int nrand(int);

int main(int argc, char *argv[])
{
        srand(time(NULL));
        cout << nrand(numeric_limits<int>::max()) << endl;

        return 0;
}

int nrand(int n)
{
        if (n <= 0 || n > numeric_limits<int>::max())
                throw domain_error("Argument to nrand is out of range");

        const int bucket_size = numeric_limits<int>::max()/ n;
        int r;

        do r = rand() / bucket_size;
        while (r >= n);

        return r;
}
