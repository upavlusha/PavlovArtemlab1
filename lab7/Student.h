#ifndef STUDENT_H
#define STUDENT_H

#include <iosfwd>

class Student {
    static int nextId;
    const int id;
    char* name;
    int course;
    int group;
    const int record;

public:
    Student(const char* name, int course, int group, int record);
    Student(const Student& s);
    Student& operator=(const Student&) = delete;
    virtual ~Student();

    int getId() const;
    const char* getName() const;
    int getCourse() const;
    int getGroup() const;
    int getRecord() const;
    void setName(const char* value);
    void setCourse(int value);
    void setGroup(int value);
    virtual double average() const;

    friend std::ostream& operator<<(std::ostream& out, const Student& s);
};

class FirstSession : public Student {
    int grades[4];

public:
    FirstSession(const char* name, int course, int group, int record, const int* grades);
    FirstSession(const FirstSession& s);
    int getFirstGrade(int i) const;
    void setFirstGrade(int i, int grade);
    double firstAverage() const;
    double average() const override;

    friend std::ostream& operator<<(std::ostream& out, const FirstSession& s);
};

class SecondSession : public FirstSession {
    int grades[5];

public:
    SecondSession(const char* name, int course, int group, int record,
                  const int* first, const int* second);
    SecondSession(const SecondSession& s);
    int getSecondGrade(int i) const;
    void setSecondGrade(int i, int grade);
    double average() const override;

    friend std::ostream& operator<<(std::ostream& out, const SecondSession& s);
};

#endif
