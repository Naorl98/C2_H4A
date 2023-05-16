#ifndef TEAM2
#define TEAM2
#include <string>
#include "Team.hpp"

namespace ariel
{

    using namespace std;
    class Team2 : public Team
    {
    public:
        Team2();
        Team2(Character * leader);
        ~Team2();
       void add(Character *other);
        Character * find(Team * other);
        void attack(Team * other);

    private:
        vector<Character *> characters;
    };
}
#endif