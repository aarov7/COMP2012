/* File: student1.h */
#include "course.h"
enum Department { CBME, CIVL, CSE, ECE, IELM, MAE };

class Student
{
private:
    std::string name;
    Department dept;
    float GPA;
    Course* enrolled; 
    int num_courses;

public:
    Student(std::string n, Department d, float x) :
        name(n), dept(d), GPA(x), enrolled(nullptr), num_courses(0) { }
    std::string get_name() const;
    Department get_department() const;
    float get_GPA() const;
    bool add_course(const Course& c);
    bool drop_course(const Course& c);
};
