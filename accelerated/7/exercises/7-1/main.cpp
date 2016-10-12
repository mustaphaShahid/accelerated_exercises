#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using std::vector;
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
        string s;
        map<string, int> counters; // store each word and an associated counter
        map<int, vector<string> > rcounters;

        // read the input, keeping track of each word and how often we see it
        while (cin >> s)
                ++counters[s];

        // write the words and associated counts
        for (map<string, int>::const_iterator it=counters.begin(); it!=counters.end(); ++it)
                rcounters[it->second].push_back(it->first);

        for (map<int, vector<string> >::const_iterator it=rcounters.begin(); it!=rcounters.end(); ++it)
                for (vector<string>::const_iterator iter=it->second.begin(); iter!=it->second.end(); ++iter)
                        cout << *iter << "\t" << it->first << endl;

        return 0;
}
