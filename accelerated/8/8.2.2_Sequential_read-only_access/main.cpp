#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

template <class In, class X> 
In find(In begin, In end, const X& x);

int main(int argc, char *argv[])
{
        vector<string> v;
        v.push_back("boom");
        v.push_back("bang");
        v.push_back("diggy");

        cout << *(find(v.begin(), v.end(), "bang")+1) << endl; // it prints diggy
        return 0;
}

template <class In, class X> 
In find(In begin, In end, const X& x)
{
        while (begin != end && *begin != x)
                ++begin;
        return begin;
}
