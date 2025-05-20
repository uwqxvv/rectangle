#include "rectangle.h"
using namespace std;

void touchRectangle() {
    Rectangle r(6, 9);
    return;
}

int main() {
    Rectangle r1(3, 4);
    touchRectangle();
    r1.show(cout);
    cout << Rectangle::getRectangleCount() << endl;
    return 0;
}