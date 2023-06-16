#ifndef COURSE_H        /* File: course.h */
#define COURSE_H 
#include<string>
#include<iostream>
class Course 
{
  private:
    std::string code;

  public:
    Course(const std::string& s) : code(s) { }
    ~Course() { std::cout << "destruct course: " << code << std::endl; }
    void print() const { std::cout << code; }
};

#endif
