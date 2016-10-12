#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::cerr;

int main(int argc, char *argv[])
{
        // vectors have to be kept aligned
        vector<string> v_students;
        vector<double> v_grades;

        string student;

        // CTRL-D to break
        cout << "enter name (CTRL-D to escape)" << endl;
        while (cin >> student) {
                v_students.push_back(student);        
                cout << "enter midterm and final grades consecutavely: " << endl;
                double midterm, final;
                cin >> midterm >> final;
                cout << "enter homeworks for student ";
                vector<double> v_homeworks;
                double homework;

                // non number to break
                while(cin >> homework)
                        v_homeworks.push_back(homework);

                // sort to find median
                sort(v_homeworks.begin(), v_homeworks.end());

                // get median
                typedef vector<double>::size_type sz;
                sz size = v_homeworks.size();
                if (size == 0) {
                        cout << "exiting due to homework size being 0" << endl;
                        exit(EXIT_FAILURE);
                }
                sz mid = size / 2;
                double median = size % 2 == 0 ? (v_homeworks[mid] + v_homeworks[mid-1]) / 2 : v_homeworks[mid];

                // final grade of this student pushed
                double grade = 0.2 * midterm + 0.4 * final + 0.4 * median;
                v_grades.push_back(grade);

                cin.clear();
                string redundant;
                cin >> redundant;
                cout << "enter name:" << endl;
        }

        // print out students and their grades
        for (int i=0; i<v_grades.size(); i++)
                cout << v_students[i] << " " << v_grades[i] << endl;

        return 0;
}
