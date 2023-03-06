#include <iostream>
#include <math.h>

using namespace std;

class Point {
protected:
    int x, y;
public:

    Point() : x(0), y(0)
    {
        cout << typeid(this).name() << " : default constuctor \n";
        show();
    }
    Point(int x, int y) : x(x), y(y)
    {
        cout << typeid(this).name() << " : constructor with parametrs\n";
        show();
    }
    Point(Point& obj) : x(obj.x), y(obj.y)
    {
        cout << typeid(this).name() << " : copy costructor \n";
        show();
    }

    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    void set_x(int x)
    {
        this->x = x;
    }
    void set_y(int y)
    {
        this->y = y;
    }
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void show() {
        cout << "x = " << x << " y = " << y << '\n';
    }
    int dist_to_origin()
    {
        return sqrt(x * x + y * y);
    }

    ~Point()
    {
        cout << typeid(this).name() << " : destructor" << '\n';
    }
};

class Point3D : public Point {
private:
    int z;
public:
    Point3D() : Point(0, 0), z(0)
    {
        cout << typeid(this).name() << " : default constuctor" << '\n';
        show();
    }
    Point3D(int x, int y, int z) : Point(x, y), z(z)
    {
        cout << typeid(this).name() << " : constructor with parametrs \n";
        show();
    }
    Point3D(Point3D& obj) : Point(obj), z(obj.z)
    {
        cout << typeid(this).name() << " : copy costructor \n";
        show();
    }

    void show() {
        cout << "x = " << x << " y = " << y << " z = " << z << '\n';
    }
    int dist_to_origin() {
        int xy = Point::dist_to_origin();
        xy *= xy;
        return sqrt(xy + z * z);
    }
    ~Point3D()
    {
        cout << typeid(this).name() << " :destructor" << '\n';
    }
};

class Section {
private:
    Point pt_start;
    Point pt_end;
public:
    Section() : pt_start(0, 0), pt_end(0, 0)
    {
        cout << typeid(this).name() << " : default constuctor\n";
        show();
    }
    Section(int x0, int y0, int x1, int y1) : pt_start(x0, y0), pt_end(x1, y1)
    {
        cout << typeid(this).name() << " : constructor with parametrs \n";
        show();
    }
    Section(Point pt0, Point pt1) : pt_start(pt0), pt_end(pt1)
    {
        cout << typeid(this).name() << " : constructor with parametrs \n";
        show();
    }
    Section(Section& obj) : pt_start(obj.pt_start), pt_end(obj.pt_end)
    {
        cout << typeid(this).name() << " : copy costructor \n";
        show();
    }

    void show() {
        cout << "x0 = " << pt_start.get_x() << " y0 = " << pt_start.get_y()
            << " x1 = " << pt_end.get_x() << " y1 = " << pt_end.get_y() << '\n';
    }
    int get_length() {
        int dx = pt_start.get_x() - pt_end.get_x();
        int dy = pt_start.get_y() - pt_end.get_y();
        return sqrt(dx * dx + dy * dy);
    }

    ~Section()
    {
        cout << typeid(this).name() << " : destructor" << '\n';
    }
};

class Section_PTR {
private:
    Point* pt_start;
    Point* pt_end;
public:
    Section_PTR()
    {
        pt_start = new Point();
        pt_end = new Point();
        cout << typeid(this).name() << " : default constuctor \n";
        show();
    }
    Section_PTR(int x0, int y0, int x1, int y1)
    {
        pt_start = new Point(x0, y0);
        pt_end = new Point(x1, y1);
        cout << typeid(this).name() << " : constructor with parametrs \n";
        show();
    }
    Section_PTR(Point pt0, Point pt1) {
        pt_start = new Point(pt0);
        pt_end = new Point(pt1);
        cout << typeid(this).name() << " : constructor with parametrs \n";
        show();
    }
    Section_PTR(Section_PTR& obj)
    {
        pt_start = new Point(*obj.pt_start);
        pt_end = new Point(*obj.pt_end);
        cout << typeid(this).name() << " : copy costructor \n";
        show();
    }
    void show();

    int get_length();

    ~Section_PTR()
    {
        cout << typeid(this).name() << " : destructor of Section_PTR" << '\n';
        delete pt_start;
        delete pt_end;
    }
};

void Section_PTR::show() {
    cout << "x0 = " << pt_start->get_x() << " y0 = " << pt_start->get_y()
        << " x1 = " << pt_end->get_x() << " y1 = " << pt_end->get_y() << '\n';
}

int Section_PTR::get_length() {
    int dx = pt_start->get_x() - pt_end->get_x();
    int dy = pt_start->get_y() - pt_end->get_y();
    return sqrt(dx * dx + dy * dy);
}

class Parent {
public:
    int b;
    Parent() {
        b = 0;
        cout << typeid(this).name() << " : default constuctor\n";
    }

    ~Parent()
    {
        cout << typeid(this).name() << " : destructor" << '\n';
    }
};

class Heir : public Parent {
    int a;
};

int main()
{
    char choice;
    char skip;
    do {
        cout << "Select and enter the appropriate number:\n"
            "   1 - static creating of object \n"
            "   2 - dynamic creating of object\n"
            "   3 - composition\n"
            "   4 - creating an object of the parent class using the constructor of the heir class\n"
            "   5 - agregation\n"
            "   6 - in the parent class there is a constructor and a destructor, and in the heir class there is neither(creating Parent)\n"
            "   7 - in the parent class there is a constructor and a destructor, and in the heir class there is neither(creating Heir)\n"
            "   q - exit\n";
        cin >> choice;
        switch (choice) {
        case '1': {
            Point point;
            break;
        }
        case '2': {
            Point3D* point3 = new Point3D();
            // создается переменная-указатель, создается объект в памяти и возвращается его адрес, этот адрес записывается в созданную переменную-указатель
            delete point3;
            break;
        }
        case '3': {
            Point point1;
            // создается обьект
            Point point2 = point1;
            // создание обьекта через конструктор копирования
            point1.set(3, 3);
            point2.set(1, 1);
            Section section(point1, point2);
            // создание обьекта через конструктор копирования         
            break;
        }
        case '4': {
            Point* point = new Point3D();
            break;
        }
        case '5': {
            Section_PTR section;
            break;
        }
        case '6': {
            Parent parent;
            break;
        }
        case '7': {
            Heir heir;
            break;
        }
        }
        do {
            cout << "   Enter 's' to go next:\n";
            cin >> skip;
        } while (skip != 's');
    } while (choice != 'q');
    return 0;
}