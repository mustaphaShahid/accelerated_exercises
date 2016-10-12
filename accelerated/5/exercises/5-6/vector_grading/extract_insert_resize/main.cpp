#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
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

        students = extract_fails(students);
        sort(students.begin(), students.end(), compare);

        cout << endl;
        cout << "passing students:" << endl;
        students_print(students, maxlen);
        cout << endl;

        return 0;
}
