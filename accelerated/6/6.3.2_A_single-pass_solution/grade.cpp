#include <stdexcept>
#include <vector>
#include "grade.hpp"
#include "median.hpp"
#include "Student_info.hpp"

using std::domain_error;
using std::vector;

// definitions for the grade functions from 4.1/52, 4.1.2/54, 4.2.2/63 
double grade(double midterm, double final, double homework)
{
        return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const std::vector<double>& hw)
{
        if (hw.size() == 0)
                throw domain_error("student has done no homework");
        return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
        return grade(s.midterm, s.final, s.homework);
}

double grade_aux(const Student_info& s)
{
        try {
                return grade(s);
        } catch (domain_error e) {
                return grade(s.midterm, s.final, 0);
        }
}

bool fgrade(const Student_info& s)
{
        return grade_aux(s) < 60;
}

bool pgrade(const Student_info& s)
{
        return !fgrade(s);
}
