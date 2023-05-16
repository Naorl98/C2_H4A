#ifndef STEAM
#define STEAM
#include <string>
#include "Team.hpp"

namespace ariel
{

    using namespace std;
    class SmartTeam : public Team
    {
    public:
        SmartTeam();
        SmartTeam(Character * leader);
        ~SmartTeam();;
        void add(Character *other);
        Character * find(Team * other);
        void attack(Team * other);

    private:
        vector<Character *> characters;
    };
}
#endif