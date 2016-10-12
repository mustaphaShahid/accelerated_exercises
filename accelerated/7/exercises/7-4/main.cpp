#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::map;
using std::string;
using std::vector;
using std::istream;
using std::find_if;
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

bool space(char c);
bool not_space(char c);
vector<string> split(const string& str);
map<string, vector<int> > xref(istream&, vector<string> (const string&) = split);
vector<string> find_urls(const string&);
string::const_iterator url_end(string::const_iterator, string::const_iterator);
string::const_iterator url_beg(string::const_iterator, string::const_iterator);
bool not_url_char(char);

int main(int argc, char *argv[])
{
        // call xref using split by default
        map<string, vector<int> > ret = xref(cin);

        // write results

        for (map<string, vector<int> >::const_iterator it=ret.begin(); it!=ret.end(); ++it) {
                // write the word
                cout << it->first << " occurs on line(s):";

                // followed by one or more line numbers
                vector<int>::const_iterator line_it = it->second.begin();
                cout << *line_it; // write the first line number

                ++line_it;
                // write the rest of the line numbers, if any
                while (line_it != it->second.end()) {
                        cout <<","<<*line_it;
                        ++line_it;
                }

                // write a new line to seperate each word from the next
                cout << endl << endl;
        }

        return 0;
}

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&))
{
        string line;
        int line_number = 0;
        map<string, vector<int> > ret;

        // read the next line
        while (getline(in, line)) {
                ++line_number;

                // break the input line into words
                vector<string> words = find_words(line);
                sort(words.begin(), words.end());
                words.erase(unique(words.begin(), words.end()),words.end());

                // remember that each word occurs on the current line
                for (vector<string>::const_iterator it=words.begin(); it!=words.end(); ++it)
                        ret[*it].push_back(line_number);
        }
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        in.clear();

        return ret;
}

vector<string> split(const string& str)
{
        typedef string::const_iterator iter;
        vector<string> ret;

        iter i = str.begin();
        while (i != str.end()) {

                // ignore leading blanks
                i = find_if(i, str.end(), not_space);

                // find end of next word
                iter j = find_if(i, str.end(), space);

                // copy the characters i [i, j)
                if (i != str.end())
                        ret.push_back(string(i, j));
                i = j;
        }
        return ret;
}

bool space(char c)
{
        return isspace(c);
}

bool not_space(char c)
{
        return !isspace(c);
}

vector<string> find_urls(const string& s)
{
        vector<string> ret;
        typedef string::const_iterator iter;
        iter b = s.begin(), e = s.end();

        // look through the entire input
        while (b != e) {

                // look for one or more letters followed by ://
                b = url_beg(b, e);

                // if we found it
                if (b != e) {
                        // get the rest of the URL
                        iter after = url_end(b, e);

                        // remember the URL
                        ret.push_back(string(b, after));

                        // advance b and check for more URLs on this line
                        b = after;
                }
        }
        return ret;
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
        return find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
        // characters, in addition to alphanumerics, that can appear in a URL
        static const string url_ch = "~;/?:@=&$-_.+*'(),";

        // see whether c can appear in a URL and return the negative
        return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
        static const string sep = "://";

        typedef string::const_iterator iter;

        // i marks where the separator was found
        iter i = b;

        while ((i = search(i, e, sep.begin(), sep.end())) != e) {

                // make sure the separator isn't at the beginning or end of the line
                if (i != b && i + sep.size() != e) {

                        // beg marks the beginning of the protocol-name
                        iter beg = i;
                        while (beg != b && isalpha(beg[-1]))
                                --beg;

                        // is there at least one appropriate character before and after the separator?
                        if (beg != i && !not_url_char(i[sep.size()]))
                                return beg;
                }

                // the separator we found wasn't part of a URL advance i past this separator
                i += sep.size();
        }
        return e;
}

