#include <stdexcept>
#include <algorithm>
#include <vector>
#include "grade.hpp"
#include "median.hpp"
#include "Student_info.hpp"

using std::domain_error;
using std::vector;
using std::rotate;

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

bool fgrade(const Student_info& s)
{
        return grade(s) < 60;
}

/*
 * std::vector<Student_info> extract_fails(std::vector<Student_info>& students)
 * {
 *         vector<Student_info> fail;
 *         vector<Student_info>::iterator iter = students.begin();
 * 
 *         while (iter != students.end()) {
 *                 if (fgrade(*iter)) {
 *                         fail.push_back(*iter);
 *                         iter = students.erase(iter);
 *                 } else {
 *                         iter++;
 *                 }
 *         }
 * 
 *         return fail;
 * }
 */

std::vector<Student_info> extract_fails(std::vector<Student_info>& students)
{
        // vector<Student_info>::size_type sz = students.size();
        int jmp = 0;
        for (vector<Student_info>::size_type i=0; i<students.size(); i++) {
                if (!fgrade(students[i])) {
                        students.insert(students.begin(), students[i]);
                        i++;
                        jmp++;
                }
        }
        students.erase(students.begin()+jmp, students.end());
        return students;
}
