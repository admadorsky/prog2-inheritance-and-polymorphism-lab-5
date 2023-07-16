#ifndef PROG2_INHERITANCE_AND_POLYMORPHISM_LAB_5_SHAPES_H
#define PROG2_INHERITANCE_AND_POLYMORPHISM_LAB_5_SHAPES_H
#include <string>

using namespace std ;

class Shape {
public:
    virtual void Scale(float scaleFactor) = 0 ;
    virtual void Display() const = 0 ;
    virtual ~Shape() { } ;
};

class Shape2D : virtual public Shape {
public:
    void ShowArea() const ;

    virtual float Area() const = 0 ;
    virtual string GetName2D() const = 0 ;

    bool operator>(const Shape2D &rhs) const ;
    bool operator<(const Shape2D &rhs) const ;
    bool operator==(const Shape2D &rhs) const ;


};

class Shape3D : virtual public Shape {
public:
    void ShowVolume() const ;

    virtual float Volume() const = 0 ;
    virtual string GetName3D() const = 0 ;

    bool operator>(const Shape3D &rhs) const ;
    bool operator<(const Shape3D &rhs) const ;
    bool operator==(const Shape3D &rhs) const ;
};

class Square : public Shape2D {
public:
    float _side_length ;
    Square() ;
    Square(float side_length) ;

    float Area() const ;
    string GetName2D() const ;

    void Display() const ;
    void Scale(float scaleFactor) ;
};

class Triangle : public Shape2D {
public:
    float _base ;
    float _height ;
    Triangle() ;
    Triangle(float base, float height) ;

    float Area() const ;
    string GetName2D() const ;

    void Display() const ;
    void Scale(float scaleFactor) ;
};

class Circle : public Shape2D {
public:
    float _radius ;
    Circle() ;
    Circle(float radius) ;

    float Area() const ;
    string GetName2D() const ;

    void Display() const ;
    void Scale(float scaleFactor) ;
};

class TriangularPyramid : public Shape3D, private Triangle {
public:
    float _height ;
    Triangle _base ;
    TriangularPyramid() ;
    TriangularPyramid(float height, float base_base, float base_height) ;

    float Volume() const ;
    string GetName3D() const ;

    void Display() const ;
    void Scale(float scaleFactor) ;
};

class Cylinder : public Shape3D, private Circle {
public:
    float _height ;
    Circle _base ;
    Cylinder() ;
    Cylinder(float height, float radius) ;

    float Volume() const ;
    string GetName3D() const ;

    void Display() const ;
    void Scale(float scaleFactor) ;
};

class Sphere : public Shape3D, private Circle {
public:
    Circle _cross_section ;
    Sphere() ;
    Sphere(float radius) ;

    float Volume() const ;
    string GetName3D() const ;

    void Display() const ;
    void Scale(float scaleFactor) ;
};

#endif //PROG2_INHERITANCE_AND_POLYMORPHISM_LAB_5_SHAPES_H
