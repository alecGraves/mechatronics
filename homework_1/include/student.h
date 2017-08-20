/**
student.h

purpose: contains student struct
created by Alec Graves
*/
namespace schoolpeople
{

struct Student
{
    private:
        int _numCourses;
        int *_credit;
        char *_grade;

    public:
    /**
    Sets the grades to an initial value, deletes any current values.

    @param creditIn: int array of length numIn, number of hours for each course
    @param gradeIn: char array of length numIn, capital ascii letter grade earned for each course
    @param numIn: number of courses in creditIn and gradeIn
    */
        void SetGrades(int creditIn[], char gradeIn[], int numIn)
        {
            //dealloc old arrays
            delete[] _credit;
            delete[] _grade;

            //alloc new arrays
            _credit = new int[numIn];
            _grade = new char[numIn];

            //copy new values
            for (int i(0); i < numIn; ++i)
            {
                _credit[i] = creditIn[i];
                _grade[i] = gradeIn[i];
            }

            //update length
            _numCourses = numIn;
            
        }
        
        /**
        Adds a grade to the arrays

        @param creditIn: int, number of hours in the course
        @param gradeIn: char, capital ascii letter grade earned in the course
        */
        void AddGrade(int creditIn, char gradeIn)
        {
            //store location of old arrays
            int * oldCred = _credit;
            char * oldGrade = _grade;
            
            //alloc new arrays
            _credit = new int[_numCourses + 1];
            _grade = new char[_numCourses + 1];

            //copy old array
            for (int i(0); i < _numCourses; ++i)
            {
                _credit[i] = oldCred[i];
                _grade[i] = oldGrade[i];
            }

            //copy new value
            _credit[_numCourses] = creditIn;
            _grade[_numCourses] = gradeIn;

            //update length
            _numCourses += 1;

            //dealloc old arrays
            delete[] oldCred;
            delete[] oldGrade;
        }

        /**
        Returns the current GPA of the student with the given courses

        @return: numeric GPA as double
        */
        double GetGPA()
        {
            int hours(0);
            int weightedGrades(0);

            for(int i(0); i < _numCourses; ++i)
            {
                //ascii conversion, mult. by weight
                weightedGrades += std::max(4 - ((int)_grade[i] - 65), 0) * _credit[i];
                //total hours
                hours += _credit[i];
            }

            return (double) weightedGrades / hours;
        }

    Student()
        : _numCourses(0), _credit(NULL), _grade(NULL)
    {}

    ~Student()
    {
        delete[] _credit;
        delete[] _grade;
    }

};//struct student

}//namespace
