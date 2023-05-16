#ifndef CHARACTER_C
#define CHARACTER_C
#include <string>
#include "Point.hpp"
namespace ariel
{

    using namespace std;
    class Character
    {
    public:
        Character();
        Character(Point location, int points, string name);
        Character(int points);
        bool isAlive();
        void setLocation(Point newloc);
        double distance(Character *other);
        void hit(int sum);
        string getName();
        string getType();
        void setType(string kind);
        int getPoints();
        Point getLocation();
        string print();

    private:
        string Type;
        Point location;
        int points;
        string name;
    };
}
#endif