#include <iostream>

using std::cout;
using std::endl;

void swap(int *x, int *y);

int main(int argc, char *argv[])
{
        int x = 3;
        int y = 5;
        swap(&x, &y);
        cout << "x: " << x << ", y: " << y << endl;
        return 0;
}

void swap(int *x, int *y)
{
        int temp = *x;
        *x = *y;
        *y = temp;
}
