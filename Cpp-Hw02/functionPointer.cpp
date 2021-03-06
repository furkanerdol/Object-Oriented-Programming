// HW02_131044065_Furkan_Erdol
// functionPointer.cpp
//
// Created on 24/10/2015 by Furkan Erdol
//
// Description
//
// return_mod function : 
//      Returns the array index of the first mode element of a given array
//      If there is not a mode element function returns index of first element
//
// equals functions :
//      Checks two element of a given with each other according to the equation
//      Returns true or false
//
//Note: n1, n2, m1, m2 variable names are taken from PS

#include <iostream>
#include <cstdlib>

using namespace std;

class DayOfYear {
public:

    DayOfYear(int dayValue = 1, int monthValue = 1) : day(dayValue), month(monthValue) {
        /*Intentionally empty*/
    }
    void input(); // There is no function
    void output() const; // There is no function
    int day;
    int month;
};

struct Person {
    char name;
    int age;
    double height; // as meters
    double weight; // as kilogram

};

// Returns the array index of the first mode element of a given array
int return_mode(const void * base, size_t num, size_t size,
        bool (* equals) (const void *, const void *));

// Checks two element of a given with each other according to the equation
// If equal return true otherwise returns false
bool equals_int(const void * n1, const void * n2);
bool equals_char(const void * n1, const void * n2);
bool equals_double(const void * n1, const void * n2);
bool equals_DayOfYear(const void * n1, const void * n2);
bool equals_Person(const void * n1, const void * n2);

int main(int argc, char** argv) {

    // Try to char array
    char charArr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'd', 'h', 'h', 'h'};
    cout << endl << ">>>TRY TO CHAR ARRAY" << endl;
    cout << "Index of the mode element of the array : ";
    cout << return_mode(charArr, sizeof (char), 10, equals_char);
    cout << endl;

    // Try to integer array
    int intArr[10] = {1, 4, 4, 2, 2, 3, 2, 3, 2, 3};
    cout << endl << ">>>TRY TO INTEGER ARRAY" << endl;
    cout << "Index of the mode element of the array : ";
    cout << return_mode(intArr, sizeof (int), 10, equals_int);
    cout << endl;

    // Try to double array
    double doubleArr[10] = {1.3, 1.0, 4.3, 4.4, 5.2, 3.7, 12.4, 12.4, 220.8, 3.1};
    cout << endl << ">>>TRY TO DOUBLE ARRAY" << endl;
    cout << "Index of the mode element of the array : ";
    cout << return_mode(doubleArr, sizeof (double), 10, equals_double);
    cout << endl;

    // Try to double DayOfYear class array
    DayOfYear a(1, 2), b(2, 11), c(24, 2), d(24, 1), e(6, 5);
    DayOfYear DayOfYearArr[5] = {a, b, c, d, e};
    cout << endl << ">>>TRY TO DayOfYear CLASS ARRAY" << endl;
    cout << "Index of the mode element of the array : ";
    cout << return_mode(DayOfYearArr, sizeof (DayOfYear), 5, equals_DayOfYear);
    cout << endl;

    // Try to Person struct array
    Person p1 = {'S', 25, 1.78, 68.4},
           p2 = {'K', 20, 1.63, 52.3},
           p3 = {'F', 20, 1.82, 70.5},
           p4 = {'M', 45, 1.90, 95.4},
           p5 = {'F', 20, 1.82, 70.5};
    Person PersonArr[5] = {p1, p2, p3, p4, p5};
    cout << endl << ">>>TRY TO Person STRUCT ARRAY" << endl;
    cout << "Index of the mode element of the array : ";
    cout << return_mode(PersonArr, sizeof (Person), 5, equals_Person);
    cout << endl << endl;

    return 0;
}

bool equals_int(const void * n1, const void * n2) {

    int* m1 = (int*) n1;
    int* m2 = (int*) n2;

    if (*m1 == *m2)
        return true;
    else
        return false;
}

bool equals_char(const void * n1, const void * n2) {

    char* m1 = (char*) n1;
    char* m2 = (char*) n2;

    if (*m1 == *m2)
        return true;
    else
        return false;
}

bool equals_double(const void * n1, const void * n2) {

    double* m1 = (double*) n1;
    double* m2 = (double*) n2;

    if (*m1 == *m2)
        return true;
    else
        return false;
}

bool equals_DayOfYear(const void * n1, const void * n2) {

    DayOfYear* m1 = (DayOfYear*) n1;
    DayOfYear* m2 = (DayOfYear*) n2;

    if ((m1->day == m2->day) && (m1->month == m2->month))
        return true;
    else
        return false;
}

bool equals_Person(const void * n1, const void * n2) {

    Person* m1 = (Person*) n1;
    Person* m2 = (Person*) n2;

    if ((m1->name == m2->name) && (m1->age == m2->age) && (m1->height == m2->height)
            && (m1->weight == m2->weight))
        return true;
    else
        return false;

}

int return_mode(const void * base, size_t num, size_t size,
        bool (* equals) (const void *, const void *)) {

    unsigned char* first = (unsigned char*) base;
    unsigned char* last = (unsigned char*) base + (num * size);

    int counterA = 1; // Number of equal elements
    int counterB = 0; // Number of equal elements
    int indexMod;

    for (unsigned char* location = (unsigned char*) base; location < last; location += num) {

        for (unsigned char* locationB = location + num; locationB < last; locationB += num) {
            if (equals(location, locationB) == true)
                counterA++;
        }

        if (counterA > counterB) {
            indexMod = (location - first) / num;
            counterB = counterA;
        }

        counterA = 1;

    }

    return indexMod;

}

