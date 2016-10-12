#include <iostream>

using std::string;
using std::cout;
using std::endl;

bool is_palindrome(const string&);

int main(int argc, char *argv[])
{
        string palindrome = "madam";
        string notPalindrome = "miss";
        cout << is_palindrome(palindrome) << endl;
        cout << is_palindrome(notPalindrome) << endl;
        return 0;
}

bool is_palindrome(const string& s)
{
        return equal(s.begin(), s.end(), s.rbegin());
}
