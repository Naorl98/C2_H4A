#include <iostream>
#include <stack>
#include "Cowboy.hpp"
#include <math.h>
using namespace std;
namespace ariel{   

    Cowboy::Cowboy(): Character(110), boolets(6){
        this->setType("C");

    }
    Cowboy::Cowboy(string name, Point location): Character(location, 110, name){
        boolets = 6;
        this->setType("C");
    }
    void Cowboy::reload(){
        boolets += 6;
    }
    bool Cowboy::hasboolets(){
        return boolets > 0;
    }
    void Cowboy::shoot(Character * other){
        if(this->isAlive() && boolets > 0){
            cout << this->getName() + " shoot " + other->getName() <<endl;
            other->hit(10);
            boolets -= 1;
        }
    }          
}