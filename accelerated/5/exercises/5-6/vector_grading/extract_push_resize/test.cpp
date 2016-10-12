#include <iostream>
#include <vector>
#include "Student_info.hpp"
#include "grade.hpp"

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
        clock_t begin = clock();

        // START
        int sample = 10000;

        // passing student example
        Student_info example_pass;
        example_pass.name = "Solid";
        example_pass.midterm = 100;
        example_pass.final = 100;
        vector<double> homework_pass;
        homework_pass.push_back(100);
        homework_pass.push_back(100);
        example_pass.homework = homework_pass;

        // failing student example
        Student_info example_fail;
        example_fail.name = "Saif";
        example_fail.midterm = 1;
        example_fail.final = 1;
        vector<double> homework_fail;
        homework_fail.push_back(1);
        homework_fail.push_back(1);
        example_fail.homework = homework_fail;
        

        /*
         * T passes;
         * T fails;
         */
        vector<Student_info> passes;
        // vector<Student_info> fails;

        for (int i=0; i<sample; i++) {
                passes.push_back(example_pass);
                passes.push_back(example_fail);
        }

        passes = extract_fails(passes);

        // the following was just to check if everything is following to plan
        cout << "passes:" << endl;
        /*
         * for (vector<Student_info>::const_iterator iter=passes.begin(); iter!=passes.end(); iter++)
         *         cout << iter->name << endl; 
         */

        // END

        clock_t end = clock();
        double time_spend = (double)(end-begin) / CLOCKS_PER_SEC;

        cout << "time taken: " << time_spend;

        return 0;
}
