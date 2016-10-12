#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::accumulate;
using std::back_inserter;

int main(int argc, char *argv[])
{
        vector<string> strings;
        string concatenated;
        strings.push_back("helo");
        strings.push_back("peeps");
        strings.push_back("bam");
        concatenated = accumulate(strings.begin(), strings.end(), string(""));
        cout << concatenated << endl;
        return 0;
}
