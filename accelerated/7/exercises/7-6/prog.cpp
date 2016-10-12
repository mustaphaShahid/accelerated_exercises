#include "prog.hpp"
#include <list>

using std::vector;
using std::string;
using std::istream;
using std::getline;
using std::map;
using std::logic_error;
using std::domain_error;
using std::cout;
using std::endl;
using std::list;

Grammar read_grammar(istream& in)
{
        Grammar ret;
        string line;

        // read the input
        while (getline(in, line)) {

                // split the input into words
                vector<string> entry = split(line);
                if (!entry.empty())
                        // use the categoryto store the associated rule
                        ret[entry[0]].push_back(Rule(entry.begin()+1, entry.end()));
        }
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

vector<string> gen_sentence(Grammar& g)
{
        vector<string> ret;
        gen_aux(g, "<sentence>", ret);
        return ret;
}

bool bracketed(string& s)
{
        return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

void gen_aux(Grammar& g, const string& word, vector<string>& ret)
{
        // load rule
        Grammar::const_iterator it = g.find(word);
        const Rule_collection& c = it->second;
        vector<string> rules = it->second[nrand(c.size())];

        // unwind
        vector<string>::iterator i = rules.begin();
        while (!rules.empty()) {
                if (!bracketed(*i)) {
                        ret.push_back(*i);
                        rules.erase(rules.begin());
                } else {
                        Grammar::const_iterator it = g.find(*i);
                        const Rule_collection& c = it->second;
                        int n = nrand(c.size());

                        vector<string>::const_iterator iter = g[*i][n].begin();
                        rules.insert(i+1, iter, iter+g[*i][n].size());
                        rules.erase(rules.begin());
                        i = rules.begin();
                }
        }
}

// return a random integer in the range [0, n)
int nrand(int n)
{
        if (n <= 0 || n > RAND_MAX)
                throw domain_error("Argument to nrand is out of range");

        const int bucket_size = RAND_MAX / n;
        int r;

        do r = rand() / bucket_size;
        while (r >= n);

        return r;
}
