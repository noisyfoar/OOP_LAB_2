#include <iostream>
#include <math.h>

using namespace std;

class Point {
protected:
    int x, y;
public:

    Point();
    Point(int x, int y);
    Point(Point& obj);

    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);
    void set(int x, int y);

    void show();
    int dist_to_origin();

    ~Point();
};

class Point3D : public Point {
private:
    int z;
public:
    Point3D();
    Point3D(int x, int y, int z);
    Point3D(Point3D& obj);

    void show();
    int dist_to_origin();
    ~Point3D();
};

class Section {
private:
    Point pt_start;
    Point pt_end;
public:
    Section();
    Section(int x0, int y0, int x1, int y1);
    Section(Point pt0, Point pt1);
    Section(Section& obj);

    void show();
    int get_length();

    ~Section();
};

class Section_PTR {
private:
    Point* pt_start;
    Point* pt_end;
public:
    Section_PTR();
    Section_PTR(int x0, int y0, int x1, int y1);
    Section_PTR(Point pt0, Point pt1);
    Section_PTR(Section_PTR& obj);

    void show();
    int get_length();

    ~Section_PTR();
};


int main()
{
    return 0;
}