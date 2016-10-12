#include <list>
#include <iostream>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
using std::islower;

list<string> extract_notlower(list<string>&);
bool islower(const string&);

int main(int argc, char *argv[])
{
        list<string> word_list;
        string word;
        cout << "Keep entering words followed by C^D" << endl;
        while (cin >> word) {
                word_list.push_back(word);
        }

        list<string> notlower = extract_notlower(word_list);
        cout << endl;

        cout << "****************************" << endl;
        for (list<string>::const_iterator iter=word_list.begin(); iter!=word_list.end(); iter++)
                cout << *iter << endl;
        cout << "****************************" << endl;
        for (list<string>::const_iterator iter=notlower.begin(); iter!=notlower.end(); iter++)
                cout << *iter << endl;

        return 0;
}

bool islower(const string& s)
{
        for (string::const_iterator iter=s.begin(); iter!=s.end(); iter++)
                if (!islower(*iter))
                        return false;

        return true;

}

list<string> extract_notlower(list<string>& words)
{
        list<string> notlower;
        list<string>::iterator iter = words.begin();

        while (iter != words.end()) {
                if (!islower(*iter)) {
                        notlower.push_back(*iter);
                        iter = words.erase(iter);
                } else {
                        iter++;
                }
        }

        return notlower;
}
