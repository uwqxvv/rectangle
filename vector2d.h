#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Vector2D
{
private:
    double x;
    double y;
    double length;
    void recalculateLength();

public:
    Vector2D(double x, double y);
    Vector2D();
    double getX() const;
    double getY() const;
    double getLength() const;
    void setX(double x);
    void setY(double y);
    Vector2D operator+(const Vector2D &other) const;
    Vector2D operator-(const Vector2D &other) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;
    Vector2D operator-() const;
    Vector2D &operator+=(const Vector2D &other);
    Vector2D &operator-=(const Vector2D &other);
    bool operator==(const Vector2D &other) const;
    bool operator!=(const Vector2D &other) const;
    friend ostream &operator<<(ostream &os, const Vector2D &vector);
};

void Vector2D::recalculateLength() {
    this->length = sqrt(this->x * this->x + this->y * this->y);
}

Vector2D::Vector2D()
{
    this->x = 0;
    this->y = 0;
    this->length = 0;
}

Vector2D::Vector2D(double x, double y)
{
    this->x = x;
    this->y = y;
    this->recalculateLength();
}

double Vector2D::getX() const
{
    return this->x;
}

double Vector2D::getY() const
{
    return this->y;
}

double Vector2D::getLength() const
{
    return this->length;
}

void Vector2D::setX(double x)
{
    this->x = x;
    this->recalculateLength();
}

void Vector2D::setY(double y)
{
    this->y = y;
    this->recalculateLength();
}

Vector2D Vector2D::operator+(const Vector2D &other) const
{
    return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D &other) const
{
    return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator*(double scalar) const
{
    return Vector2D(this->x * scalar, this->y * scalar);
}

Vector2D Vector2D::operator/(double scalar) const
{
    return Vector2D(this->x / scalar, this->y / scalar);
}

Vector2D Vector2D::operator-() const
{
    return Vector2D(-this->x, -this->y);
}

Vector2D &Vector2D::operator+=(const Vector2D &other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

bool Vector2D::operator==(const Vector2D &other) const
{
    return (this->x == other.x) && (this->y == other.y);
}

bool Vector2D::operator!=(const Vector2D &other) const
{
    return !(*this == other);
}

ostream &operator<<(ostream &os, const Vector2D& vector)
{
    os << "(" << vector.x << "; " << vector.y << ")";
    return os;
}
