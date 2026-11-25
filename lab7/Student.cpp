#include "Student.h"

#include <cstring>
#include <ostream>
#include <stdexcept>

using namespace std;

int Student::nextId = 0;

Student::Student(const char* name, int course, int group, int record)
    : id(++nextId), name(nullptr), course(course), group(group), record(record) {
    setName(name);
}

Student::Student(const Student& s) : Student(s.name, s.course, s.group, s.record) {
}

Student::~Student() {
    delete[] name;
}

int Student::getId() const { return id; }
const char* Student::getName() const { return name; }
int Student::getCourse() const { return course; }
int Student::getGroup() const { return group; }
int Student::getRecord() const { return record; }
void Student::setCourse(int value) { course = value; }
void Student::setGroup(int value) { group = value; }

void Student::setName(const char* value) {
    char* copy = new char[strlen(value) + 1];
    strcpy(copy, value);
    delete[] name;
    name = copy;
}

double Student::average() const {
    return 0;
}

ostream& operator<<(ostream& out, const Student& s) {
    return out << "ID " << s.id << ", " << s.name << ", курс " << s.course
               << ", группа " << s.group << ", зачётка " << s.record;
}

FirstSession::FirstSession(const char* name, int course, int group, int record, const int* first)
    : Student(name, course, group, record) {
    for (int i = 0; i < 4; ++i) {
        grades[i] = first[i];
    }
}

FirstSession::FirstSession(const FirstSession& s) : Student(s) {
    for (int i = 0; i < 4; ++i) {
        grades[i] = s.grades[i];
    }
}

int FirstSession::getFirstGrade(int i) const {
    if (i < 0 || i >= 4) {
        throw out_of_range("Номер оценки первой сессии");
    }
    return grades[i];
}

void FirstSession::setFirstGrade(int i, int grade) {
    if (i < 0 || i >= 4) {
        throw out_of_range("Номер оценки первой сессии");
    }
    grades[i] = grade;
}

double FirstSession::firstAverage() const {
    double sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return sum / 4;
}

double FirstSession::average() const {
    return firstAverage();
}

ostream& operator<<(ostream& out, const FirstSession& s) {
    const Student& base = s;
    out << base << ", первая сессия:";
    for (int grade : s.grades) {
        out << ' ' << grade;
    }
    return out;
}

SecondSession::SecondSession(const char* name, int course, int group, int record,
                             const int* first, const int* second)
    : FirstSession(name, course, group, record, first) {
    for (int i = 0; i < 5; ++i) {
        grades[i] = second[i];
    }
}

SecondSession::SecondSession(const SecondSession& s) : FirstSession(s) {
    for (int i = 0; i < 5; ++i) {
        grades[i] = s.grades[i];
    }
}

int SecondSession::getSecondGrade(int i) const {
    if (i < 0 || i >= 5) {
        throw out_of_range("Номер оценки второй сессии");
    }
    return grades[i];
}

void SecondSession::setSecondGrade(int i, int grade) {
    if (i < 0 || i >= 5) {
        throw out_of_range("Номер оценки второй сессии");
    }
    grades[i] = grade;
}

double SecondSession::average() const {
    double sum = firstAverage() * 4;
    for (int grade : grades) {
        sum += grade;
    }
    return sum / 9;
}

ostream& operator<<(ostream& out, const SecondSession& s) {
    const FirstSession& first = s;
    out << first << ", вторая сессия:";
    for (int grade : s.grades) {
        out << ' ' << grade;
    }
    return out;
}
