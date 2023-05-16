#include <iostream>
#include <stack>
#include "Team.hpp"
#include <math.h>
using namespace std;
namespace ariel
{

    Team::Team()
    {
        count = 0;
    }
    Team::Team(Cowboy *lead)
    {
        leader = lead;
        count = 1;
        count_cowboys = 1;
        count_ninjas = 0;
        cowboys.push_back(lead);
    }
    Team::Team(Ninja *lead) 
    {
        leader = lead; 
        count = 1;
        count_ninjas = 1;
        count_cowboys = 0;
        ninjas.push_back(lead);
    }
    Team::~Team()
    {
        for (unsigned long int i = 0; i < count_cowboys; i++)
        {
            free(*cowboys.end());
            cowboys.pop_back();
        }
        for (unsigned long int j = 0; j < count_ninjas; j++)
        {
            free(*ninjas.end());
            ninjas.pop_back();
        }
    }
    void Team::add(Ninja *other)
    {
        if (count < 10)
        {
            ninjas.push_back(other);
            count++;
            count_ninjas++;
        }
    }
    void Team::add(Cowboy *other)
    {
        if (count < 10)
        {
            cowboys.push_back(other);
            count++;
            count_cowboys++;
        }
    }
    void Team::print()
    {
        for (unsigned long int i = 0; i < count_cowboys; i++)
        {
           cout << cowboys[i]->print() << endl;  

        }
        for (unsigned long int j = 0; j < count_ninjas; j++)
        {
            cout <<ninjas[j]->print() << endl;
        }
    }
    int Team::stillAlive()
    {
        int sum = 0;
        for (unsigned long int i = 0; i < count_cowboys; i++)
        {
            if (cowboys[i]->isAlive())
            {
                sum++;
            }
        }
        for (unsigned long int j = 0; j < count_ninjas; j++)
        {
            if (ninjas[j]->isAlive())
                sum++;
        }
        return sum;
    }
    Character *Team::getLeader()
    {
        return leader;
    }
    Character *Team::find(Team *other)
    {
        Character *toAttack;
        double lowest = 2147483647;
        for (unsigned long int i = 0; i < other->getCountCow(); i++)
        {
            if (other->getCowboy(i)->isAlive())
            {
                if (lowest > other->getCowboy(i)->distance(leader))
                {
                    toAttack = other->getCowboy(i);
                    lowest = other->getCowboy(i)->distance(leader);
                }
            }
        }

        for (unsigned long int j = 0; j < other->getCountNinja(); j++)
        {
            if (other->getNinja(j)->isAlive())
            {
                if (lowest > other->getNinja(j)->distance(leader))
                {
                    toAttack =other->getNinja(j);
                    lowest = other->getNinja(j)->distance(leader);

                }
            }
        }
        return toAttack;
    }
    int Team::getCountCow()
    {
        return count_cowboys;
    }
    int Team::getCountNinja()
    {
        return count_ninjas;
    }
    Character *Team::getNinja(unsigned long int index)
    {
        return ninjas[index];
    }
    Character *Team::getCowboy(unsigned long int index)
    {
        return cowboys[index];
    }

    void Team::attack(Team *other)
    {
        cout << "in attack" << endl;
        if (other->stillAlive() == 0 || this->stillAlive() == 0){
            return;
        }
        Character *toAttack;

        if (!leader->isAlive())
        {
            Character *save;
            int lowest = 2147483647;
            for (unsigned long int i = 0; i < count_cowboys; i++)
            {
                if (cowboys[i]->isAlive())
                {
                    if (lowest > leader->distance(cowboys[i]))
                    {
                        save = cowboys[i];
                        lowest = leader->distance(cowboys[i]);
                    }
                }
            }
            for (unsigned long int j = 0; j < count_ninjas; j++)
            {
                if (ninjas[j]->isAlive())
                {
                    if (lowest > leader->distance(ninjas[j]))
                    {
                        save = ninjas[j];
                        lowest = leader->distance(ninjas[j]);
                    }
                }
            }
            leader = save;
        }
        toAttack = find(other);
        for (unsigned long int i = 0; i < count_cowboys; i++)
        {
            if (cowboys[i]->isAlive())
            {
                if (cowboys[i]->hasboolets())
                {
                    cowboys[i]->shoot(toAttack);
                    if (!toAttack->isAlive())
                    {
                        cout << toAttack->getName() + " died" << endl;
                        if (other->stillAlive() == 0)
                            return;
                        toAttack = find(other);
                    }
                }
                else
                    cowboys[i]->reload();
            }
        }
        for (unsigned long int j = 0; j < count_ninjas; j++)
        {
            if (ninjas[j]->isAlive())
            {
                if (ninjas[j]->distance(toAttack) < 1)
                {
                    ninjas[j]->slash(toAttack);
                    if (!toAttack->isAlive())
                    {
                        if (other->stillAlive() > 0)
                            return;
                        toAttack = find(other);
                    }
                }
                else
                    ninjas[j]->move(toAttack);
            }
        }
    }
}
