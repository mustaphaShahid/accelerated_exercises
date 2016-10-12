#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.hpp"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

bool fgrade(const Student_info& s);
std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif
