#include "Student_info.hpp"
#include "grade.hpp"
#include "median.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using std::find;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::transform;
using std::back_inserter;
using std::transform;
using std::ostream;
using std::string;
using std::accumulate;
using std::remove_copy;

bool did_all_hw(const Student_info&);
double average(const vector<double>&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);

vector<Student_info> delete_incomplete(vector<Student_info>&);

// write_analysis function
void write_analysis(ostream&, const string&, double (const Student_info&), const vector<Student_info>&, const vector<Student_info>&);
// analysis function
double analysis(const vector<Student_info>&, double (const Student_info&));

int main(int argc, char *argv[])
{
        // students who did and didnt do all their homework
        vector<Student_info> did, didnt;

        // read the student records and partition them
        Student_info student;
        while (read(cin, student)) {
                /*
                 * if (did_all_hw(student))
                 *         did.push_back(student);
                 * else
                 *         didnt.push_back(student);
                 */
                did.push_back(student);
        }

        // verify that the analyses will show us something
/*
 *         if (did.empty()) {
 *                 cout << "No student did all the homework!" << endl;
 *                 return 1;
 *         }
 *         if (didnt.empty()) {
 *                 cout << "Every student did all the homework!" << endl;
 *                 return 1;
 *         }
 * 
 *         write_analysis(cout, "median", grade_aux, did, didnt);
 *         write_analysis(cout, "average", average_grade, did, didnt);
 *         write_analysis(cout, "average", optimistic_median, did, didnt);
 */
        didnt = delete_incomplete(did);

        cout << "did everything" << endl;
        typedef vector<Student_info>::const_iterator iter;
        for (iter it=did.begin(); it!=did.end(); it++)
                cout << it->name << endl;

        cout << "*************************" << endl;

        cout << "didnt do everything" << endl;
        for (iter it=didnt.begin(); it!=didnt.end(); it++)
                cout << it->name << endl;


        return 0;

}


double average(const vector<double>& v)
{
        return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
        return grade(s.midterm, s.final, average(s.homework));
}


double optimistic_median(const Student_info& s)
{
        vector<double> nonzero;
        remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

        if (nonzero.empty())
                return grade(s.midterm, s.final, 0);
        else
                return grade(s.midterm, s.final, median(nonzero));
}

void write_analysis(ostream& out, const string& name, double analysis_aux(const Student_info&), const vector<Student_info>& did, const vector<Student_info>& didnt)
{
        out << name << ": median(did) = " << analysis(did, analysis_aux) << ", median(didnt) = " << analysis(didnt, analysis_aux) << endl;
}

double analysis(const vector<Student_info>& students, double analysis_aux(const Student_info&))
{
        vector<double> grades;

        transform(students.begin(), students.end(), back_inserter(grades), analysis_aux);
        return median(grades);
}

bool did_all_hw(const Student_info& s)
{
        return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

vector<Student_info> delete_incomplete(vector<Student_info>& students)
{
        // vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
        vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), did_all_hw);
        vector<Student_info> fail(iter, students.end());
        students.erase(iter, students.end());

        return fail;
}
