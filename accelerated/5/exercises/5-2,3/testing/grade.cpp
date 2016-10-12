#include "grade.hpp"

bool fgrade(int s)
{
        return s < 60;
}

T extract_fails(T& students)
{
        T fail;
        T::iterator iter = students.begin();

        while (iter != students.end()) {
                if (fgrade(*iter)) {
                        fail.push_back(*iter);
                        iter = students.erase(iter);
                } else {
                        iter++;
                }
        }

        return fail;
}
