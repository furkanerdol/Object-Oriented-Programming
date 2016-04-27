// HW03_131044065_Furkan_Erdol
// class.cpp
//
// Created on 24/10/2015 by Furkan Erdol
//
// Description
//
// Triangle class: Creates triangle and makes necessary calculations

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Triangle {
public:
    Triangle(double AValue, double BValue, double CValue);
    Triangle(double AValue, double BValue);
    Triangle(double allSides);
    Triangle();

    // Input and output functions
    void input();
    void output() const;

    // Set function for triangle
    void set(double newSideA, double newSideB, double newSideC);

    // Get functions for triangle
    double getA() const { return A; }
    double getB() const { return B; }
    double getC() const { return C; }

    double angleA() const; // Calculates angle of 'A' side
    double angleB() const; // Calculates angle of 'B' side
    double angleC() const; // Calculates angle of 'C' side

    // Calculates perimeter of triangle
    double perimeterTriangle() const { return A + B + C; }
    // Calculates area of triangle
    double areaTriangle() const;
    // Returns true if the triangle is a right angle triangle otherwise returns false
    bool rightAngleTriangle() const; 
   
private:
    double A; // 'A' side of the triangle
    double B; // 'B' side of the triangle
    double C; // 'C' side of the triangle
    const static double PI; // Necessary for the math calculation (pi number)
    void testInput() const; // Checks the triangle validity
};

const double Triangle::PI = 3.14159265;

int main(int argc, char** argv) {

    // Triangle 1
    Triangle m;

    m.set(5, 5, 5);
    m.output();
    cout << endl << "-Angel of A:" << m.angleA() << endl;
    cout << "-Angel of B:" << m.angleB() << endl;
    cout << "-Angel of C:" << m.angleC() << endl;
    cout << "-Perimeter of triangle:" << m.perimeterTriangle();
    cout << endl << "-Area of triangle:" << m.areaTriangle();
    if (m.rightAngleTriangle() == true)
        cout << endl << "-Triangle is a right angle triangle" << endl;
    else
        cout << endl << "-Triangle is not a right angle triangle" << endl;

    // Triangle 2
    Triangle m2(6, 8, 10);

    m2.output();
    cout << endl << "-Angel of A:" << m2.angleA() << endl;
    cout << "-Angel of B:" << m2.angleB() << endl;
    cout << "-Angel of C:" << m2.angleC() << endl;
    cout << "-Perimeter of triangle:" << m2.perimeterTriangle();
    cout << endl << "-Area of triangle:" << m2.areaTriangle();
    if (m2.rightAngleTriangle() == true)
        cout << endl << "-Triangle is a right angle triangle" << endl;
    else
        cout << endl << "-Triangle is not a right angle triangle" << endl;

    // Triangle 3
    Triangle m3;
    
    cout << endl;
    m3.input();
    m3.output();
    cout << endl << "-Angel of A:" << m3.angleA() << endl;
    cout << "-Angel of B:" << m3.angleB() << endl;
    cout << "-Angel of C:" << m3.angleC() << endl;
    cout << "-Perimeter of triangle:" << m3.perimeterTriangle();
    cout << endl << "-Area of triangle:" << m3.areaTriangle();
    if (m3.rightAngleTriangle() == true)
        cout << endl << "-Triangle is a right angle triangle" << endl;
    else
        cout << endl << "-Triangle is not a right angle triangle" << endl << endl;


    return 0;
}

Triangle::Triangle(double AValue, double BValue, double CValue)
: A(AValue), B(BValue), C(CValue) {
    testInput();
}

Triangle::Triangle(double AValue, double BValue)
: A(AValue), B(BValue), C(1.0) {
    testInput();
}

Triangle::Triangle(double allSides)
: A(allSides), B(allSides), C(allSides) {
    testInput();
}

Triangle::Triangle()
: A(1.0), B(1.0), C(1.0) {
    /*Intentionally empty*/
}

void Triangle::testInput() const {
    
    if (A <= 0.0 || B <= 0.0 || C <= 0.0) {
        cerr << endl << "Illegal input values!" << endl << endl;
        exit(1);
    }

    if ((A + B) <= C || (B + C) <= A || (A + C) <= B) {
        cerr << endl << "Triangle cannot be according to this input values!" << endl << endl;
        exit(1);
    }
}

void Triangle::input() {
    
    cout << "Please enter sides (A, B, C)" << endl;

    cout << "A: ";
    cin >> A;
    cout << "B: ";
    cin >> B;
    cout << "C: ";
    cin >> C;

    testInput();
}

void Triangle::output() const {
    
    cout << endl << ">>>TRIANGEL" << endl;
    cout << "Side of A:" << A;
    cout << "   Side of B:" << B;
    cout << "   Side of C:" << C << endl;
}

void Triangle::set(double newSideA, double newSideB, double newSideC) {
    
    A = newSideA;
    B = newSideB;
    C = newSideC;

    testInput();
}

double Triangle::angleA() const {
    return (acos(((C * C)+(B * B)-(A * A)) / (2 * (B * C)))*180) / PI;
}

double Triangle::angleB() const {
    return (acos(((A * A)+(C * C)-(B * B)) / (2 * (A * C)))*180) / PI;
}

double Triangle::angleC() const {
    return (acos(((A * A)+(B * B)-(C * C)) / (2 * (A * B)))*180) / PI;
}

bool Triangle::rightAngleTriangle() const {

    int angA = angleA();
    int angB = angleB();
    int angC = angleC();

    if (angA == 90 || angB == 90 || angC == 90)
        return true;

    else
        return false;
}

double Triangle::areaTriangle() const {

    double halfPer = perimeterTriangle() / 2.0; // Half of the perimeter

    // Calculates and returns area of triangle
    return sqrt(halfPer * (halfPer - A)*(halfPer - B)*(halfPer - C));
}







