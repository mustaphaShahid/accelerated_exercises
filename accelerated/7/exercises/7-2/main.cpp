#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include "grade.hpp"
#include "Student_info.hpp"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::map;

string compute_grade(double);

int main(int argc, char *argv[])
{
        vector<Student_info> students;
        Student_info record;
        string::size_type maxlen = 0; // the length of the longest name

        // read and store all the students data.
        // Invariant: students contains all the student records read so far
        // maxlen contains the length of the longest name in students
        while (read(cin, record)) {
                // find length of longest name
                maxlen = max(maxlen, record.name.size());
                students.push_back(record);
        }

        // alphabetize the student records
        sort(students.begin(), students.end(), compare);

        map<string, int> map_grades;
        // map_grades[compute_grade(3)]++;
        // write the names and grades
        for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
                // write the name, padded on the right to maxlen + 1 characters
                // cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

                // compute and write the grade
                try {
                        /*
                         * double final_grade = grade(students[i]);
                         * streamsize prec = cout.precision();
                         * cout << setprecision(3) << final_grade << setprecision(prec);
                         */
                        ++map_grades[compute_grade(grade(students[i]))];
                } catch (domain_error e) {
                        cout << e.what();
                }
                // cout << endl;
        }

        for (map<string, int>::const_iterator iter=map_grades.begin(); iter!=map_grades.end(); iter++)
                cout << iter->first << " " << iter->second << endl;

        return 0;
}

string compute_grade(double grade)
{
        if (grade >= 90 && grade <= 100)
                return "A";
        else if (grade >= 80)
                return "B";
        else if (grade >= 70)
                return "C";
        else if (grade >= 60)
                return "D";
        else if (grade < 60 && grade >= 0)
                return "F";
        else return "N/A";
}
