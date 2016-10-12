#include <iostream>
#include <time.h>
#include "grade.hpp"

using std::list;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
        clock_t begin = clock();

        // START
        int sample = 400000;

        int example_pass = 75;
        int example_fail = 35;

        T passes;
        T fails;

        for (int i=0; i<sample; i++) {
                passes.push_back(example_pass);
                passes.push_back(example_fail);
        }

        fails = extract_fails(passes);

        // the following was just to check if everything is following to plan
        /*
         * cout << "passes:" << endl;
         * for (list<int>::const_iterator iter=passes.begin(); iter!=passes.end(); iter++)
         *         cout << *iter << endl; 
         * for (list<int>::const_iterator iter=fails.begin(); iter!=fails.end(); iter++)
         *         cout << *iter << endl; 
         */

        // END

        clock_t end = clock();
        double time_spend = (double)(end-begin) / CLOCKS_PER_SEC;

        cout << "time taken: " << time_spend;

        return 0;
}
