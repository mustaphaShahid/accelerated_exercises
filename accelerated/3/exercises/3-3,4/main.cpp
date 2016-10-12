#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::sort;

int main(int argc, char *argv[])
{
        string word;
        cout << "Enter words" << endl;

        vector<string> v_words;

        // CTRL-D to exit loop 
        while (cin >> word)
                v_words.push_back(word);

        // print out words sorted for debugging
        sort(v_words.begin(), v_words.end());
        for (vector<string>::size_type i = 0; i < v_words.size(); i++)
                cout << v_words[i] << " ";
        cout << endl;

        // print out count for each word
        word = v_words[0];
        int counter = 0;
        for (vector<string>::size_type i = 0; i < v_words.size(); i++) {
                if (word != v_words[i]) {
                        cout << word << ": " << counter << endl;
                        word = v_words[i];
                        counter = 1;
                } else {
                        counter++;
                }
        }
        cout << v_words[v_words.size()-1] << ": " << counter << endl;

        // print out length of shortest and longest word
        string::size_type shortest = v_words[0].size();
        string::size_type longest = v_words[v_words.size()-1].size();
        cout << "shortest word: " << shortest << endl;
        cout << "longest word: " << longest << endl;

        return 0;
}
