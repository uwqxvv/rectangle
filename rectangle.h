#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include "vector2d.h"

class Rectangle{

private:
    double width;
    double height;
    void fixNegative();
    // inline static int count = 0;
    static int& accessCount() {
        static int s_count = 0;
        return s_count;
    }
    void handleCreation();
public:
    static int getRectangleCount();
    Rectangle();
    Rectangle (Vector2D diagonal);
    Rectangle(double side);
    Rectangle(double height, double width);
    double aspect_ratio() const;
    void show(std::ostream &os) const;
    double area() const;
    double diagonal() const;
    double perimeter() const;
    bool square() const;
    Vector2D getDiagonalVector() const;
    Rectangle& setSize(double height, double width);
    Rectangle& changeSides();
    bool operator== (const Rectangle &other) const;
    bool operator!= (const Rectangle &other) const;
    bool fitsInto(const Rectangle &other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
};

void Rectangle::handleCreation() {
    accessCount()++;
    std::cerr << "Rectangle created! Current count: " << accessCount() << std::endl;
}

int Rectangle::getRectangleCount() {
    return accessCount();
}

void Rectangle::fixNegative() {
    if(width < 0 ){
        std::cerr << "cannot set width to " << width << " – is negative" << std::endl;
        width = 0; height = 0;

    }
    if(height < 0){
        std::cerr << "cannot set height to " << height << " – is negative" << std::endl;
        width = 0; height = 0;
    }
}

Rectangle::Rectangle() : width(0), height(0) {
    handleCreation();
};

Rectangle::Rectangle(Vector2D diagonal) {
    width = diagonal.getX();
    height = diagonal.getY();
    fixNegative();
    handleCreation();
}

Rectangle::Rectangle (double side){
    this -> width = side;
    this -> height = side;
    fixNegative();
    handleCreation();
}

double Rectangle::aspect_ratio() const{
    return this -> width / this -> height;
}

bool Rectangle::operator== (const Rectangle &other) const{
    if(this -> height == other.height && this -> width == other.width)
        return true;
    return false;
}

bool Rectangle::operator!= (const Rectangle &other) const{
    if(this -> height != other.height || this -> width != other.width)
        return true;
    return false;
}

Rectangle::Rectangle (double height, double width){
    this -> width = width;
    this -> height = height;
    fixNegative();
    handleCreation();
}

void Rectangle::show(std::ostream &os) const{
    char ch = 219;
    for(int h = 0; h < this-> height; h++){
        for(int w = 0; w < width; w++ )
            os << ch;
        os << std::endl;
    }
}

Vector2D Rectangle::getDiagonalVector() const{
    return Vector2D(this->width, this->height);
}

double Rectangle::area() const{
    return this -> width * this -> height;
}

double Rectangle::diagonal() const{
    return sqrt(this -> width* this -> width  + this -> height * this -> height) ;
}

double Rectangle::perimeter() const{
    return 2 * this -> height + 2 * this -> width;
}
 bool Rectangle::square() const{
    return (this -> height == this -> width);
}

bool Rectangle::fitsInto(const Rectangle &other) const{
    if(( this -> height <= other.width && this -> width <= other.height) || (this -> height >= other.width && this -> width >= other.height)) return true;
    if(( this -> height <= other.height && this -> width <= other.width) || (this -> height >= other.height && this -> width >= other.width)) return true;
    return false;
}
Rectangle& Rectangle::changeSides(){
    std::swap(this -> height, this -> width);
    return *this;
 }
Rectangle& Rectangle::setSize(double height, double width){
    this -> height = height;
    this -> width = width;
    fixNegative();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle){
    os << rectangle.height << ' ' << rectangle.width;
    return os;
}
