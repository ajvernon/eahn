#include <iostream>
#include <cmath>
#include <vectors.hpp>
using namespace std;

#define PI 3.14159265

Vector::Vector () { // The initialisation function if no arguments are called
    xComponent = 0;
    yComponent = 0;
    setPublic();
}

Vector::Vector (long double x, long double y) { // The initialisation function
    xComponent = x;
    yComponent = y;
    setPublic();
}

void Vector::setValues(long double x, long double y) {  // The function to change the values
    xComponent = x;
    yComponent = y;
    setPublic();
}

void Vector::setPublic(){       // The function to set the public values
    publicX = xComponent;
    publicY = yComponent;
}

void Vector::setVector(Vector inputVector) {        // The function to set the values, based off of another vector
    long double x = inputVector.publicX;
    long double y = inputVector.publicY;
    xComponent = x;
    yComponent = y;
    setPublic();
}

long double Vector::magnitude () {      // The function to determine the magnitude of the vector
    long double magnitude;
    long double x = xComponent;
    long double y = yComponent;
    magnitude = (sqrt((x*x) + (y*y)));
    return (magnitude);
}

long double Vector::angle () {      // The function to determine the angle of the vector
    long double angle;
    long double x = xComponent;
    long double y = yComponent;
    angle = atan(y/x);
    return angle;
}

long double radToDeg (long double radian){      // This function converts an angle from radians to degrees
    long double degree;
    degree = radian*180/PI;
    return degree;
}

void Vector::eval () {      // This function prints out the data associated with the vector
    cout << "Vector X component: " << xComponent << "\n";
    cout << "Vector Y component: " << yComponent << "\n";
    cout << "Vector magnitude: " << magnitude() << "\n";
    cout << "Vector angle: " << angle() << "\n";
    cout << "and in degrees: " << radToDeg(angle()) << "\n\n";
}

long double scalarProduct (Vector input1, Vector input2) {      // This function determines the scalar product of two
    long double scalar;                                         // given vectors
    long double xInput1 = input1.publicX;
    long double yInput1 = input1.publicY;
    long double xInput2 = input2.publicX;
    long double yInput2 = input2.publicY;
    scalar = (xInput1*xInput2) + (yInput1*yInput2);
    return scalar;
}

long double angleBetweenVectors (Vector input1, Vector input2){ // This function determines the angle between two
    long double angle;                                          // given vectors
    long double scalar;
    scalar = scalarProduct(input1, input2);
    long double input1Mag = input1.magnitude();
    long double input2Mag = input2.magnitude();
    if (input1Mag == 0)
        angle = input2.angle();
    else if (input2Mag == 0)
        angle = input1.angle();
    else
        angle = acos(((scalar)/(input1Mag*input2Mag)));
    return angle;
}

void Vector::addValues (long double x, long double y) {
    setValues((xComponent + x), (yComponent + y));
}

void Vector::addVector (Vector input1){
    setValues((xComponent + input1.publicX), (yComponent + input1.publicY));
}
