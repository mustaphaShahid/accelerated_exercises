#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::cout;
using std::endl;

vector<string> hcat(const vector<string>&, const vector<string> &);
string::size_type width(const vector<string>&);

int main(int argc, char *argv[])
{
        vector<string> v1;
        vector<string> v2;

        v1.push_back("hello peeps");
        v1.push_back("i gotta story for yous");
        v1.push_back("i was in da mountains");

        v2.push_back("put a can in it");
        v2.push_back("i dont care");
        v2.push_back("abt your stupida stories");
        v2.push_back("i needsa monies");
        v2.push_back("an stufs");

        vector<string> v_hcat = hcat(v2, v1);

        for (vector<string>::const_iterator iter=v_hcat.begin(); iter!=v_hcat.end(); iter++)
                cout << *iter << endl;

        return 0;
}

/*
 * vector<string> hcat(const vector<string>& left, const vector<string> & right)
 * {
 *         vector<string> ret;
 * 
 *         // add 1 to leave space between pictures
 *         string::size_type width1 = width(left) + 1;
 * 
 *         // indices to look at elements from left and right respectively
 *         vector<string>::size_type i = 0, j = 0;
 * 
 *         // continue until we've seen all rows from both pictures
 *         while (i!=left.size() || j!=right.size()) {
 *                 // construct new string to hold characters from both pictures
 *                 string s;
 * 
 *                 // copy a row from the left-hand side, if there is one
 *                 if (i != left.size())
 *                         s = left[i++];
 * 
 *                 // pad to full width
 *                 s += string(width1 - s.size(), ' ');
 * 
 *                 // copy a row from the right-hand side, if there is one
 *                 if (j != right.size())
 *                         s += right[j++];
 * 
 *                 // add s to the picture we're creating
 *                 ret.push_back(s);
 *         }
 *         return ret;
 * }
 */
vector<string> hcat(const vector<string>& left, const vector<string> & right)
{
        vector<string> ret;

        // add 1 to leave space between pictures
        string::size_type width1 = width(left) + 1;

        // indices to look at elements from left and right respectively
        vector<string>::const_iterator i = left.begin(), j = right.begin();

        // continue until we've seen all rows from both pictures
        while (i!=left.end() || j!=right.end()) {
                // construct new string to hold characters from both pictures
                string s;

                // copy a row from the left-hand side, if there is one
                if (i != left.end())
                        s = *i++;

                // pad to full width
                s += string(width1 - s.size(), ' ');

                // copy a row from the right-hand side, if there is one
                if (j != right.end())
                        s += *j++;

                // add s to the picture we're creating
                ret.push_back(s);
        }
        return ret;
}

/*
 * string::size_type width(const vector<string>& v)
 * {
 *         string::size_type maxlen = 0;
 *         for (vector<string>::size_type i=0; i!=v.size(); ++i)
 *                 maxlen = max(maxlen, v[i].size());
 *         return maxlen;
 * }
 */
string::size_type width(const vector<string>& v)
{
        string::size_type maxlen = 0;
        for (vector<string>::const_iterator i=v.begin(); i!=v.end(); ++i)
                maxlen = max(maxlen, i->size());
        return maxlen;
}
