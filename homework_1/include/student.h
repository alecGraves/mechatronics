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

        double GetGPA()
        {
            int sum(0);

            for(int i(0); i < _numCourses; ++i)
            {
                sum += _credit[i];
            }

            return (double) sum / _numCourses;
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