#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::numeric_limits;
using std::streamsize;

int main(int argc, char *argv[])
{
        double x;
        vector<double> v_x;

        cout << "enter as many doubles followed by an invalid" << endl;
        while (cin >> x)
                v_x.push_back(x);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        double sum = 0;
        for (vector<double>::size_type i=0; i<v_x.size(); i++) {
                sum += v_x[i];
        }
        double ave = sum / v_x.size();

        cout << "average of contents of vector: " << ave << endl;

        return 0;
}
