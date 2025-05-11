#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:

    Point(int x=0, int y=0) {
        this->x=x;
        this->y=y;
    }

    Point* moveBy(int dx, int dy) {
        x+=dx;
        y+=dy;
        return this;
    }

    void DisplayCoordinates() const {
        cout<<"Point at ("<<x<<", "<<y<<")\n";
    }
};


int main() {
    Point* p=new Point(10, 20);
    p->DisplayCoordinates();

    p->moveBy(5, -3)->moveBy(-2, 4)->moveBy(1, 1);
    p->DisplayCoordinates();

    delete p;
    return 0;
}
