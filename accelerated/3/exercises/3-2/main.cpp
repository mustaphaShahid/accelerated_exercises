#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::sort;

int main(int argc, char *argv[])
{
        double q1;
        double q2;
        double q3;
        vector<double> v_doubles;

        double x;
        while (cin >> x)
                v_doubles.push_back(x);

        sort(v_doubles.begin(), v_doubles.end());

        typedef vector<double>::size_type sz;

        // print out sorted vector
        for (sz i = 0; i < v_doubles.size(); i++)
                cout << v_doubles[i] << " ";
        cout << endl;

        sz size = v_doubles.size();
        sz mid = size / 2;

        // 2 3 3 3 4 8 9 9     #s 8,  status: pass
        // 2 4 3 8 9 3 7 8 2   #s 9,  status: not tested
        // 1 2 2 3 4 4 4 5 6 7 #s 10, status: pass
        // 2 4 3 5 6 7 4 4 2 1 #s 10, status: pass

        // all quartiles calculated here
        q2 = size % 2 == 0 ? (v_doubles[mid] + v_doubles[mid-1]) / 2 : v_doubles[mid];
        sz q1size = size / 2;
        sz q1mid = q1size / 2;
        q1 = q1size % 2 == 0 ? (v_doubles[q1mid] + v_doubles[q1mid-1]) / 2 : v_doubles[q1mid];
        sz q3mid = q1mid % 2 == 0 ? q1mid + mid : q1mid + mid+1;
        q3 = q1size % 2 == 0 ? (v_doubles[q3mid] + v_doubles[q3mid-1]) / 2 : v_doubles[q3mid];

        cout << "q1: " << q1 << endl;
        cout << "q2: " << q2 << endl;
        cout << "q3: " << q3 << endl;

        return 0;
}
