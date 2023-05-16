#ifndef TEAM
#define TEAM
#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
namespace ariel
{

    using namespace std;
    class Team
    {
    public:
        Team();
        Team(Cowboy *leader);
        Team(Ninja *leader);
        ~Team();
        int stillAlive();
        void print();
        Character * getLeader();
        int getCountCow();
        virtual Character * find(Team * other);
        int getCountNinja();
        Character * getCowboy(unsigned long int index);
        Character * getNinja(unsigned long int index);
        virtual void attack(Team *other);
        void add(Ninja *other);
        void add(Cowboy *other);

    private:
        int count;
        int count_cowboys;
        int count_ninjas;
        vector<Cowboy *> cowboys;
        vector<Ninja *> ninjas;
        Character * leader;
    };
}
#endif