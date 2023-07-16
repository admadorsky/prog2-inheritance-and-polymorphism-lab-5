#include "Shapes.h"
#include <math.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std ;

// CONSTANTS
const float pi = 3.14159f ;


// SHAPE2D -------------------------------------------------------------------------------------------------------------

/** \n Prints a statement with the 2d shape's name and area */
void Shape2D::ShowArea() const {
    cout << fixed << setprecision(2) << "The area of the " << this->GetName2D() << " is : " << this->Area() << endl ;
}

/** \n Operator overload allowing comparison of 2d shapes' areas */
bool Shape2D::operator<(const Shape2D &rhs) const {
    if (this->Area() < rhs.Area())
        return true ;
    return false ;
}

/** \n Operator overload allowing comparison of 2d shapes' areas */
bool Shape2D::operator>(const Shape2D &rhs) const {
    if (this->Area() > rhs.Area())
        return true ;
    return false ;
}

/** \n Operator overload allowing comparison of 2d shapes' areas */
bool Shape2D::operator==(const Shape2D &rhs) const {
    if (this->Area() == rhs.Area())
        return true ;
    return false ;
}


// SHAPE3D -------------------------------------------------------------------------------------------------------------

/** \n Prints a statement with the 3d shape's name and volume */
void Shape3D::ShowVolume() const {
    cout << fixed << setprecision(2) << "The volume of the " << this->GetName3D() << " is : " << this->Volume() << endl ;
}

/** \n Operator overload allowing comparison of 3d shapes' volumes */
bool Shape3D::operator<(const Shape3D &rhs) const {
    if (this->Volume() < rhs.Volume())
        return true ;
    return false ;
}

/** \n Operator overload allowing comparison of 3d shapes' volumes */
bool Shape3D::operator>(const Shape3D &rhs) const {
    if (this->Volume() > rhs.Volume())
        return true ;
    return false ;
}

/** \n Operator overload allowing comparison of 3d shapes' volumes */
bool Shape3D::operator==(const Shape3D &rhs) const {
    if (this->Volume() == rhs.Volume())
        return true ;
    return false ;
}


// SQUARE --------------------------------------------------------------------------------------------------------------

/** \n Default Constructor: Initializes side length to 0. */
Square::Square() {
    this->_side_length = 0 ;
}

/** \n Parameterized constructor.
 * @param side_length the length of one side as a float */
Square::Square(float side_length) {
    this->_side_length = side_length ;
}

/** \n Accessor function for a shape's name */
string Square::GetName2D() const {
    return "Square" ;
}

/** \n Calculates Area: ( side length ) ^ 2 */
float Square::Area() const {
    return pow(this->_side_length, 2.00f) ;
}

/** \n Displays a Square's area and side length */
void Square::Display() const {
    this->ShowArea() ;
    cout << fixed << setprecision(2) << "Length of a side: " << this->_side_length << endl ;
}

/** \n Calculates a Square's new side length for a target area scale factor */
void Square::Scale(float scaleFactor) {
    this->_side_length *= scaleFactor ;
}


// TRIANGLE ------------------------------------------------------------------------------------------------------------

/** \n Default Constructor: Initializes base and height to 0 */
Triangle::Triangle() {
    this->_base = 0 ;
    this->_height = 0 ;
}

/** \n Parameterized constructor.
 * @param base the length of the base as a float
 * @param height the length of the height as a float */
Triangle::Triangle(float base, float height) {
    this->_base = base ;
    this->_height = height ;
}

/** \n Accessor function for a shape's name */
string Triangle::GetName2D() const {
    return "Triangle" ;
}

/** \n Calculates Area: ( base * height ) / 2 */
float Triangle::Area() const {
    return ( this->_base * this->_height ) / 2 ;
}

/** \n Displays a Triangle's area, base, and height */
void Triangle::Display() const {
    this->ShowArea() ;
    cout << fixed << setprecision(2) << "Base: " << this->_base << endl ;
    cout << fixed << setprecision(2) << "Height: " << this->_height << endl ;
}

/** \n Calculates a Triangle's new side length for a target area scale factor */
void Triangle::Scale(float scaleFactor) {
    this->_base *= scaleFactor ;
    this->_height *= scaleFactor ;
}


// CIRCLE --------------------------------------------------------------------------------------------------------------

/** \n Default Constructor: Initializes radius to 0 */
Circle::Circle() {
    this->_radius = 0 ;
}

/** \n Parameterized constructor.
 * @param radius the length of the radius as a float */
Circle::Circle(float radius) {
    this->_radius = radius ;
}

/** \n Accessor function for a shape's name */
string Circle::GetName2D() const {
    return "Circle" ;
}

/** \n Calculates Area: pi * ( r ^ 2 ) */
float Circle::Area() const {
    return pi * ( pow( this->_radius, 2 ) ) ;
}

/** \n Displays a Circle's area and radius */
void Circle::Display() const {
    this->ShowArea() ;
    cout << fixed << setprecision(2) << "Radius: " << this->_radius << endl ;
}

/** \n Calculates a Triangle's new side length for a target area scale factor */
void Circle::Scale(float scaleFactor) {
    this->_radius *= scaleFactor ;
}


// TRIANGULAR PYRAMID --------------------------------------------------------------------------------------------------

/** \n Default Constructor: Initializes all values to 0 */
TriangularPyramid::TriangularPyramid() {
    this->_height = 0 ;
    this->_base._base = 0 ;
    this->_base._height = 0 ;
}

/** \n Parameterized constructor. NOTE: the base is a 2D Triangle object
 * @param height the length of the height as a float
 * @param base_base the length of the base's base as a float
 * @param base_height the length of the base's height as a float */
TriangularPyramid::TriangularPyramid(float height, float base_base, float base_height) {
    this->_height = height ;
    this->_base._base = base_base ;
    this->_base._height = base_height ;
}

/** \n Accessor function for a shape's name */
string TriangularPyramid::GetName3D() const {
    return "Triangular Pyramid" ;
}

/** \n Calculates Volume: ( 1 / 3 ) * A * h */
float TriangularPyramid::Volume() const {
    return ( 1.000f / 3.000f ) * this->_base.Area() * this->_height ;
}

/** \n Displays a Triangular Pyramid's volume and displays the base */
void TriangularPyramid::Display() const {
    this->ShowVolume() ;
    cout << fixed << setprecision(2) << "The height is: " << this->_height << endl ;
    this->_base.Display() ;
}

/** \n Calculates a Triangular Pyramid's new height and base values for a target volume scale factor */
void TriangularPyramid::Scale(float scaleFactor) {
    this->_height *= scaleFactor ;
    this->_base._base *= scaleFactor ;
    this->_base._height *= scaleFactor ;
}


// CYLINDER ------------------------------------------------------------------------------------------------------------

/** \n Default Constructor: Initializes all values to 0 */
Cylinder::Cylinder() {
    this->_base._radius = 0 ;
    this->_height = 0 ;
}

/** \n Parameterized constructor
 * @param radius the length of the radius as a float */
Cylinder::Cylinder(float height, float radius) {
    this->_base._radius = radius ;
    this->_height = height ;
}

/** \n Accessor function for a shape's name */
string Cylinder::GetName3D() const {
    return "Cylinder" ;
}

/** \n Calculates Volume: A * h */
float Cylinder::Volume() const {
    return ( this->_base.Area() * this->_height ) ;
}

/** \n Displays a Cylinder's volume and displays the base */
void Cylinder::Display() const {
    this->ShowVolume() ;
    cout << fixed << setprecision(2) << "The height is: " << this->_height << endl ;
    this->_base.Display() ;
}

/** \n Calculates a Cylinder's new height and base values for a target volume scale factor */
void Cylinder::Scale(float scaleFactor) {
    this->_height *= scaleFactor ;
    this->_base._radius *= scaleFactor ;
}


// SPHERE --------------------------------------------------------------------------------------------------------------

/** \n Default Constructor: Initializes radius to 0 */
Sphere::Sphere() {
    this->_cross_section._radius = 0 ;
}

/** \n Parameterized constructor
 * @param radius the length of the radius as a float */
Sphere::Sphere(float radius) {
    this->_cross_section._radius = radius ;
}

/** \n Accessor function for a shape's name */
string Sphere::GetName3D() const {
    return "Sphere" ;
}

/** \n Calculates Volume: ( 4 / 3 ) * pi * ( r ^ 3 ) */
float Sphere::Volume() const {
    return ( 4.000f / 3.000f ) * pi * ( pow( this->_cross_section._radius, 3.000f ) ) ;
}

/** \n Displays a Sphere's volume and displays the cross section */
void Sphere::Display() const {
    this->ShowVolume() ;
    this->_cross_section.Display() ;
}

/** \n Calculates a Sphere's new radius for a target volume scale factor */
void Sphere::Scale(float scaleFactor) {
    this->_cross_section._radius *= scaleFactor ;
}

