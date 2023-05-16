#include <iostream>
#include <stack>
#include "Character.hpp"
#include <math.h>
using namespace std;
namespace ariel{   

    Character::Character(){
        points = 0;
    }
    Character::Character(int points): points(points){
    }
    Character::Character(Point location, int points, string name): location(location), points(points), name(name){
    }
    void Character::setLocation(Point newloc){
        location = Point(newloc.GetX(), newloc.GetY());
    }

    bool Character::isAlive(){
        return points > 0;
    }
    double Character::distance(Character * other){
        return location.distance(other->getLocation());
    }
    string Character::getName(){
        return name;
    }
    string Character::getType(){
        return Type;
    }
    void Character::setType(string kind){
        Type = kind;
    }
    int Character::getPoints(){
        return points;
    }
    void Character::hit(int sum){
        int save  = points;
        points -= sum;
        if(points < 0) points =0;
        cout << name + " from " << save << " to " << points <<endl;

    }
    Point Character::getLocation(){
        return location;
    }
    string Character::print(){
        return name + + ": " + to_string(points);
    }
            
}