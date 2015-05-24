#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

using namespace std;
using namespace genv;

class Game{
protected:
    vector<vector<int>> tomb = vector<vector<int>>(9, vector<int>(9, 0));
    vector<vector<bool>> matrix = vector<vector<bool>>(9, vector<bool>(9, false));
    vector<vector<bool>> valid = vector<vector<bool>>(9, vector<bool>(9,true));

    bool win;

public:
    Game();
    Game(int tmp[9][9]);
    bool step(int x, int y, int num);
    void check();
    bool isWin();

    vector<vector<int>> getNumbers();
    vector<vector<bool>> getBaseNumbers();
    vector<vector<bool>> getValidNumbers();

};

#endif // GAME_HPP_INCLUDED
