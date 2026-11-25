#include "Student.h"

#include <iomanip>
#include <iostream>

using namespace std;

void printAverage(const char* label, double sum, int count) {
    cout << label;
    if (count == 0) {
        cout << "нет оценок\n";
    } else {
        cout << sum / count << '\n';
    }
}

int main() {
    int a[4] = {8, 7, 9, 6};
    int b[4] = {10, 8, 9, 7};
    int c[5] = {9, 6, 7, 10, 8};

    Student s("Анна", 1, 3, 1001);
    FirstSession f("Иван", 1, 3, 1002, a);
    SecondSession g("Мария", 1, 3, 1003, b, c);
    SecondSession h("Павел", 1, 4, 1004, a, c);
    Student* students[] = {&s, &f, &g, &h};
    FirstSession* first[] = {&f, &g, &h};
    SecondSession* second[] = {&g, &h};

    cout << s << '\n' << f << '\n' << g << '\n' << h << '\n';
    int group;
    cout << "Номер группы: ";
    if (!(cin >> group)) {
        return 1;
    }

    double firstSum = 0, yearSum = 0, allSum = 0;
    int firstCount = 0, yearCount = 0, allCount = 0;
    for (FirstSession* p : first) {
        if (p->getGroup() == group) {
            firstSum += p->firstAverage();
            ++firstCount;
        }
    }
    for (SecondSession* p : second) {
        if (p->getGroup() == group) {
            yearSum += p->average();
            ++yearCount;
        }
    }
    for (Student* p : students) {
        // У s ещё нет оценок.
        if (p != &s) {
            allSum += p->average();
            ++allCount;
        }
    }

    cout << fixed << setprecision(2);
    printAverage("Средний балл группы после первой сессии: ", firstSum, firstCount);
    printAverage("Средний балл группы за год: ", yearSum, yearCount);
    printAverage("Средний балл по массиву студентов с оценками: ", allSum, allCount);
}
