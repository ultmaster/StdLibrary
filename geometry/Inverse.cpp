#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}

    Point operator * (double a) const { return Point(x * a, y * a); }
    Point operator / (double a) const { return Point(x / a, y / a); }
};

struct Circle {
    Point p;
    double r;
    Circle() :p(0, 0), r(0) {}
    Circle(double _x, double _y, double _r) : p(_x, _y), r(_r) {}
};

double len2(const Point &a) { return a.x * a.x + a.y * a.y; }

Circle Inverse(Circle a) {
    double d = sqrt(len2(a.p)), r = (1 / (d - a.r) - 1 / (d + a.r)) / 2;
    a.p = a.p * (1 / (d - a.r) - r) / d, a.r = r;
    return a;
}
