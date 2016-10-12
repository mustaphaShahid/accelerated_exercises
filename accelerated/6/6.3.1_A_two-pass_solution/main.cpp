#include "Student_info.hpp"
#include "grade.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using std::remove_if;
using std::vector;

vector<Student_info> extract_fails(vector<Student_info>&);
bool pgrade(const Student_info&);

int main(int argc, char *argv[])
{
        return 0;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
        vector<Student_info> fail;
        remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
        students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
        return fail;
}

bool pgrade(const Student_info& s)
{
        return !fgrade(s);
}
