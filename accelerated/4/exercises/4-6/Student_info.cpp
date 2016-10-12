#include "Student_info.hpp"
#include <iostream>
#include <limits>
#include <stdlib.h>
#include "grade.hpp"

using std::istream;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;

bool compare(const Student_info& x, const Student_info& y)
{
        return x.name < y.name;
}

std::istream& read(std::istream& is, Student_info& s)
{
        // read and store the student's name and midterm and final exam grades
        
        double midterm, final;
        cout << "input name, midterm and final" << endl;
        is >> s.name >> midterm >> final;
        if (is.eof()) {
                return is;
        }

        vector<double> homeworks;
        cout << "enter all homeworks ending with an invalid" << endl;
        read_hw(is, homeworks); // read and store all the student's homework grades
        s.finalGrade = grade(midterm, final, homeworks);
        return is;
}

std::istream& read_hw(std::istream& in, vector<double>& hw)
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
