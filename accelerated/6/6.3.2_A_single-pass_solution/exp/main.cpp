#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool fgrade(const int&);
bool pgrade(const int&);

int main(int argc, char *argv[])
{
        vector<int> nums;
        nums.push_back(3);
        nums.push_back(0);
        nums.push_back(0);
        nums.push_back(4);

        vector<int> fail;

        remove_copy_if(nums.begin(), nums.end(), back_inserter(fail), pgrade);
        nums.erase(remove_if(nums.begin(), nums.end(), fgrade), nums.end());

        cout << "nums: " << endl;
        for (vector<int>::const_iterator iter=nums.begin(); iter!=nums.end(); iter++)
                cout << *iter << endl;

        cout << "fail: " << endl;
        for (vector<int>::const_iterator iter=fail.begin(); iter!=fail.end(); iter++)
                cout << *iter << endl;


        return 0;
}

bool pgrade(const int& i)
{
        return i != 0;
}
bool fgrade(const int& i)
{
        return i == 0;
}
