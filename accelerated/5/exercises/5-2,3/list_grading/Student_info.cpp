#include "Student_info.hpp"
#include "grade.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>

using std::istream;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::setprecision;
using std::domain_error;
using std::list;
using std::string;

bool compare(const Student_info& x, const Student_info& y)
{
        return x.name < y.name;
}

std::istream& read(std::istream& is, Student_info& s)
{
        // read and store the student's name and midterm and final exam grades
        
        cout << "input name, midterm and final" << endl;
        is >> s.name >> s.midterm >> s.final;

        cout << "enter all homeworks ending with an invalid" << endl;
        read_hw(is, s.homework); // read and store all the student's homework grades
        return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
        if (in) {
                // get rid of previous contents
                hw.clear();

                // read homework grades
                double x;
                while (in >> x)
                        hw.push_back(x);

                // clear the stream so that input will work for the next student
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return in;
}

void students_print(const list<Student_info>& students, string::size_type maxlen)
{

        // write the names and grades
        for (list<Student_info>::const_iterator iter=students.begin(); iter!=students.end(); iter++) {
                // write the name, padded on the right to maxlen + 1 characters
                cout << iter->name << string(maxlen+1 - iter->name.size(), ' ');

                // compute and write the grade
                try {
                        double final_grade = grade(*iter);
                        streamsize prec = cout.precision();
                        cout << setprecision(3) << final_grade << setprecision(prec);
                } catch (domain_error e) {
                        cout << e.what();
                }
                cout << endl;
        }
}
