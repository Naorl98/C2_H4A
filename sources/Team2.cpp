#include <iostream>
#include <stack>
#include "Team2.hpp"
#include <math.h>
using namespace std;
namespace ariel
{

    Team2::Team2(): Team()
    {
    }
    Team2::Team2(Character *lead):Team()
    {
        characters.push_back(lead);
    }

    Team2::~Team2()
    {

    }
   void Team2::add(Character *other)
    {
    }

    Character *Team2::find(Team *other)
    {
        Character * newC = new Character();
        return newC;
    }
    void Team2::attack(Team *other)
    {
        
    }
}
