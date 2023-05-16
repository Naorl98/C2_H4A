#ifndef POINT_C
#define POINT_C
#include <string>
#include <iostream>
namespace ariel{

    using namespace std;
    class Point{ 
    public:
        Point();
        Point(double x_value, double y_value);
        double distance(Point other);
        void print();
        double GetX();
        double GetY();
        Point moveTowards(Point other, double dist);
    private:
        double x_value;
        double y_value;

            
    };
}
#endif