#include <map>
#include <iostream>

using std::map;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
        map<string, int> bam;
        bam["pop"] = 1;
        bam["jenkins"] = 2;

        cout << bam["jenkins"];
        return 0;
}
