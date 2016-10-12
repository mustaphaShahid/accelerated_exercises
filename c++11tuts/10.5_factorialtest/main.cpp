#include <iostream>

using std::cout;
using std::endl;

int factorial(int n);

int main(int argc, char *argv[])
{
        cout << factorial(0) << endl;;
        return 0;
}

int factorial(int n)
{
        if (n == 0) {
                return 1;
        }
        return n * factorial(n - 1);
}
