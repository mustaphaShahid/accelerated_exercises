#include <iostream>

using std::cout;
using std::endl;

int add(int x, int y);
int mul(int x, int y);
int eval(int(*f)(int x, int y), int x, int y);

int main(int argc, char *argv[])
{
        int x = 3;
        int y = 4;
        cout << eval(add, x, y) << endl;
        cout << eval(mul, x, y) << endl;

        int(*func)(int x, int y);
        func = add;
        cout << func(x, y) << endl;
        
        return 0;
}

int add(int x, int y)
{
        return x + y;
}
int mul(int x, int y)
{
        return x * y;
}

int eval(int(*f)(int x, int y), int x, int y)
{
        return f(x, y);
}
