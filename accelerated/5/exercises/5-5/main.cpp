#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::max;

vector<string> center(const vector<string>&);
string::size_type max(const vector<string>&);

int main(int argc, char *argv[])
{
        vector<string> v_s; 
        v_s.push_back("sup guys");
        v_s.push_back("it's good to see yall");
        v_s.push_back("been a long time");
        v_s.push_back("wots crakin");

        string::size_type maxlen = max(v_s);

        cout << "maxlen " << maxlen << endl;

        for (vector<string>::const_iterator iter=v_s.begin(); iter!=v_s.end(); iter++)
                cout << string((maxlen - iter->size())/2, ' ') << *iter << endl;

        return 0;
}

vector<string> center(const vector<string>&)
{
        vector<string> d;
        return d;
}

string::size_type max(const vector<string>& v_s)
{
        string::size_type maxlen = 0;
        for (vector<string>::const_iterator iter=v_s.begin(); iter!=v_s.end(); iter++)
                maxlen = max(maxlen, iter->size());
        return maxlen;
}
