#include <iostream>
#include <stack>
#include "Ninja.hpp"
#include <math.h>
using namespace std;
namespace ariel{   

    Ninja::Ninja(): Character(){
        this->setType("N");

    }
    Ninja::Ninja(int points, int speed): Character(points), speed(speed){
        this->setType("N");

    }
    Ninja::Ninja(string name, Point location, int points ,int speed): Character(location, points, name), speed(speed){
        this->setType("N");

    }
    void Ninja::slash(Character * other){
        if(this->isAlive() && this->distance(other) < 1){
            other->hit(40);
        }
        else if(this->distance(other) > 1)
            this->move(other);
    }
    void Ninja::move(Character * other){
        int dist = speed;
        if(this->distance(other)<speed)
            this->setLocation(Point(other->getLocation().GetX(), other->getLocation().GetY()));
        else
            this->setLocation(this->getLocation().moveTowards(other->getLocation(), speed));
        cout << this->getName() + " Move to: "<< this->getLocation().GetX() << ", " << this->getLocation().GetY() << endl;
    }          
}