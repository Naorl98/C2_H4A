#include <iostream>
#include <stack>
#include "SmartTeam.hpp"
#include <math.h>
using namespace std;
namespace ariel
{

    SmartTeam::SmartTeam(): Team()
    {
    }
    SmartTeam::SmartTeam(Character *lead):Team()
    {
        characters.push_back(lead);
    }

    SmartTeam::~SmartTeam()
    {

    }
    void SmartTeam::add(Character *other)
    {
    }

    Character *SmartTeam::find(Team *other)
    {
        Character * newC = new Character();
        return newC;
    }
    void SmartTeam::attack(Team *other)
    {
        
    }
}
