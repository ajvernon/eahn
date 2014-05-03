#ifndef _VECTORS_H_INCLUDED
#define _VECTORS_H_INCLUDED

class Vector                                    // This is the (two dimensional) vector class
{
    long double xComponent, yComponent;         // The two components of the vector
public:
    Vector ();          // The initialisation function if no arguments are called
    Vector (long double, long double);          // The initialisation function
    void setValues (long double, long double);  // This function changes the values
    void setPublic();                           // This function sets the public values
    void setVector (Vector);                    // This function sets the values, based off of another vector
    long double publicX, publicY;               // The public version of the vector's values
    long double magnitude ();                   // This function determines the magnitude of the vector
    long double angle ();                       // This function determines the angle of the vector
    void eval();                                // This function prints out the data associated with the vector
    void addValues(long double, long double);   // This function adds the two arguments to the associated components
    void addVector(Vector);
};
#endif
