#include <iostream>

using std::cout;
using std::endl;

void ch(int &x);

int main(int argc, char *argv[])
{
        int y = 0;
        ch(y);
        cout << y << endl;

        return 0;
}

void ch(int &x)
{
        x = 3;
}
