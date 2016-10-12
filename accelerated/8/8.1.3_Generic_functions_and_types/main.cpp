#include <iostream>

using std::cout;
using std::endl;

template<class T>
T max(const T&, const T&);

int main(int argc, char *argv[])
{
        cout << max(3.2, 6.3) << endl;
        return 0;
}

template<class T>
T max(const T& left, const T& right)
{
        return left > right ? left : right;
}
