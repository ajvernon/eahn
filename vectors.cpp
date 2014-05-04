#include <iostream>
#include <cmath>
#include <vectors.hpp>
using namespace std;

#define PI 3.14159265

// This section of code is only of use for two-dimensional vectors. For this purpose, that is fine,
// but if I were to reuse this for other things I'd probably want to rework it to use the third dimension.

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
    long double x = inputVector.publicX;            // I made it so that you can use another vector to initialise
    long double y = inputVector.publicY;            // one so that I didn't have to type out RandoCalrissian.publicX
    xComponent = x;                                 // RandoCalrissian.publicY or whatever if I had to copy a vector.
    yComponent = y;                                 // No, I'm not ashamed of that pun.
    setPublic();                                    // I did rip it from a game called Cards Against Humanity, though. Go play it. It's fun.
}

long double Vector::magnitude () {      // The function to determine the magnitude of the vector
    long double magnitude;
    long double x = xComponent;         // I pulled this out of the other functions because basically everything vector
    long double y = yComponent;         // related cares about the magnitude of the vectors involved.
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
    degree = radian*180/PI;                     // Just in case anyone who uses this code isn't cool enough to understand
    return degree;                              // radians.
}

void Vector::eval () {      // This function prints out the data associated with the vector
    cout << "Vector X component: " << xComponent << "\n";
    cout << "Vector Y component: " << yComponent << "\n";   // This is in here entirely for testing; this is a snippet
    cout << "Vector magnitude: " << magnitude() << "\n";    // I put together just as a chunk of code I could bring in
    cout << "Vector angle: " << angle() << "\n";            // whenever I needed vectors
    cout << "and in degrees: " << radToDeg(angle()) << "\n\n";
}

long double dotProduct (Vector input1, Vector input2) {      // This function determines the dot product of two
    long double scalar;                                         // given vectors
    long double xInput1 = input1.publicX;
    long double yInput1 = input1.publicY;       // These variables are assigned because the compiler gets a bit iffy
    long double xInput2 = input2.publicX;       // about using the inputs directly in the calculation
    long double yInput2 = input2.publicY;
    scalar = (xInput1*xInput2) + (yInput1*yInput2);
    return scalar;
}

long double angleBetweenVectors (Vector input1, Vector input2){ // This function determines the angle between two
    long double angle;                                          // given vectors
    long double scalar;
    scalar = dotProduct(input1, input2);
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

void Vector::addValues (long double x, long double y) { // This function adds a value to the vector
    setValues((xComponent + x), (yComponent + y));
}

void Vector::addVector (Vector input1){ // This function adds two vectors together
    setValues((xComponent + input1.publicX), (yComponent + input1.publicY));
}

long double distanceBetweenVectors (Vector input1, Vector input2){
    long double x = input1.publicX - input2.publicX;
    long double y = input1.publicY - input2.publicY;
    return sqrt((x*x + y*y));
}
