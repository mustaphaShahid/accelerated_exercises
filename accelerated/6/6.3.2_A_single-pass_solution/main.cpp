#include "Student_info.hpp"
#include "grade.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::stable_partition;

vector<Student_info> extract_fails(vector<Student_info>&);

int main(int argc, char *argv[])
{
        
        return 0;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
        vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
        vector<Student_info> fail(iter, students.end());
        students.erase(iter, students.end());

        return fail;
}
