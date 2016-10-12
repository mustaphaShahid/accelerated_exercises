#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::toupper;
using std::find;
using std::max;
using std::setw;
using std::right;

struct line {
        string::size_type tag;
        string str;
};

line makeline(int, string);
line makeline(string str);
bool comp(const line&, const line&);
string toupper(const string&);
vector<line> setTags(const line&);
string::size_type lineLeftSpace(const vector<line>&);

int main(int argc, char *argv[])
{
        line l1 = makeline("The quick brown fox");
        line l2 = makeline("jumped over the fence");

        vector<line> v_l1 = setTags(l1);
        vector<line> v_l2 = setTags(l2);

        vector<line> all = v_l1;
        all.insert(all.end(), v_l2.begin(), v_l2.end());

        sort(all.begin(), all.end(), comp);

        string::size_type maxlen = lineLeftSpace(all);
        for (vector<line>::const_iterator iter=all.begin(); iter!=all.end(); iter++) {
                cout << right << setw(maxlen+1) << iter->str.substr(0, iter->tag) << string(4, ' ') << iter->str.substr(iter->tag, iter->str.size()-iter->tag+1) << endl;
        }

        return 0;
}

string::size_type lineLeftSpace(const vector<line>& v_s)
{
        string::size_type maxlen = 0;
        for (vector<line>::const_iterator iter=v_s.begin(); iter!=v_s.end(); iter++)
                if (iter->tag != 0)
                        maxlen = max(maxlen, iter->str.size() - iter->tag);
        return maxlen;
}

vector<line> setTags(const line& l)
{
        vector<line> ret;
        ret.push_back(l);
        for (vector<line>::size_type i=0; i<l.str.size(); i++)
                if (isspace(l.str[i])) {
                        line ln = makeline(i+1, l.str);
                        ret.push_back(ln);
                }
        return ret;
}

string toupper(const string& str)
{
        string strUpper;
        for (string::size_type i=0; i<str.size(); i++)
                strUpper += toupper(str[i]);
        return strUpper;
}

bool comp(const line& l1, const line& l2)
{
        return toupper(l1.str.substr(l1.tag, l1.tag-l1.str.size()+1)) < toupper(l2.str.substr(l2.tag, l2.tag-l2.str.size()+1));
}

line makeline(int tag, string str)
{
        line l;
        l.tag = tag;
        l.str = str;
        return l;
}

line makeline(string str)
{
        line l;
        l.tag = 0;
        l.str = str;
        return l;
}
