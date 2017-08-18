#include <iostream>
#include <student.h>

using namespace std;

int main(int argc, char **argv)
{
    const int numStart(5);
    int startCredit[numStart] = {3, 4, 3, 2, 4};
    char startGrade[numStart] = {'A', 'A', 'B', 'C', 'B'};

    auto me = new schoolpeople::Student;
    auto you = new schoolpeople::Student;

    me->SetGrades(startCredit, startGrade, numStart);
    you->SetGrades(startCredit, startGrade, numStart);

    me->AddGrade(4, 'C');
    me->AddGrade(3, 'F');
    you->AddGrade(2, 'B');
    you->AddGrade(4, 'A');

    cout << "I have a " << me->GetGPA() << " GPA." << endl;
    cout << "You have a " << you->GetGPA() << " GPA." << endl;
}