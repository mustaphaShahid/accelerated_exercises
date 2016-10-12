#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::domain_error;
using std::sort;

template<class T>
T median(vector<T>);

int main(int argc, char *argv[])
{
        double myints[] = {16.32, 2, 77, 29, 7};
        vector<double> nums (myints, myints + sizeof(myints) / sizeof(double));

        cout << median(nums);
        return 0;
}

template<class T>
T median(vector<T> v)
{
        typedef typename vector<T>::size_type vec_sz;

        vec_sz size = v.size();
        if (size == 0)
                throw domain_error("median of an empty vector");

        sort(v.begin(), v.end());

        vec_sz mid = size/2;

        return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];

}
