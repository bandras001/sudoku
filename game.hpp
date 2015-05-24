#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "widgets.hpp"

using namespace std;
using namespace genv;

class Game{
protected:
    int tomb[9][9];
    bool matrix[9][9];
public:
    Game();
    Game(int*);
    bool step(int x, int y, int num);
    bool check();

};

#endif // GAME_HPP_INCLUDED
