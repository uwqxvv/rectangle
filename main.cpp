#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include "vector2d.h"
using namespace std;

class Rectangle{

private:
    double width;
    double height;
    void fixNegative();
public:
    Rectangle();
    Rectangle (Vector2D diagonal);
    Rectangle(double side);
    Rectangle(double height, double width);
    double aspect_ratio() const;
    void show() const;
    double area() const;
    double diagonal() const;
    double perimeter() const;
    bool square() const;
    Rectangle& setSize(double height, double width);
    Rectangle& changeSides();
    void print() const;
    bool operator== (const Rectangle &other) const;
    bool operator!= (const Rectangle &other) const;
    friend ostream& operator<<(ostream& os, const Rectangle& rectangle);
};

void Rectangle :: fixNegative() {
    if(width < 0 ){
        cerr << "cannot set width to " << width << " – is negative" << endl;
        width = 0; height = 0;

    }
    if(height < 0){
        cerr << "cannot set height to " << height << " – is negative" << endl;
        width = 0; height = 0;
    }
}

Rectangle :: Rectangle() : width(0), height(0) {};
Rectangle :: Rectangle(Vector2D diagonal) {
    width = diagonal.getX();
    height = diagonal.getY();
    fixNegative();
}
Rectangle :: Rectangle (double side){
    this -> width = side;
    this -> height = side;
    fixNegative();
}
double Rectangle :: aspect_ratio() const{
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
Rectangle :: Rectangle (double height, double width){
    this -> width = width;
    this -> height = height;
    fixNegative();
}
void Rectangle :: show() const{
    char ch = 219;
    for(int h = 0; h < this-> height; h++){
        for(int w = 0; w < width; w++ )
            cout << ch;
        cout << endl;
    }
}



double Rectangle::area() const{
    return this -> width * this -> height;
}
double Rectangle::diagonal() const{
    return sqrt(this -> width* this -> width  + this -> height * this -> height) ;
}
 double Rectangle:: perimeter() const{
    return 2 * this -> height + 2 * this -> width;
 }
 bool Rectangle:: square() const{
    return (this -> height == this -> width);
}
Rectangle& Rectangle:: changeSides(){
    swap(this -> height, this -> width);
    return *this;
 }
Rectangle& Rectangle:: setSize(double height, double width){
    this -> height = height;
    this -> width = width;
    fixNegative();
    return *this;
}

void Rectangle :: print() const{
    cout << this -> height << ' ' << this -> width << endl;

}

ostream& operator<<(ostream& os, const Rectangle& rectangle) {
    os << rectangle.height << ' ' << rectangle.width;
    return os;
}

int main() {
    Rectangle r1(1, 2), r2(1, 2), r3(2, 1);
    cout << (r1 == r2) << endl;
    return 0;
}
