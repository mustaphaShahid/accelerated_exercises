#include <iostream>
#include <map>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
        string s;
        map<string, int> counters; // store each word and an associated counter

        // read the input, keeping track of each word and how often we see it
        while (cin >> s)
                ++counters[s];

        // write the words and associated counts
        for (map<string, int>::const_iterator it=counters.begin(); it!=counters.end(); ++it)
                cout << it->first << "\t" << it->second << endl;

        return 0;
}
