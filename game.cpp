#include "game.hpp"

struct point{
    point(){x = 0; y = 0;}
    point(int x, int y):x(x),y(y){}
    int x;
    int y;
};

Game::Game(){
    for(int i = 0 ; i < 9; i++){
        for(int j = 0; j < 9; j++){
            tomb[i][j] = 0;
            matrix[i][j]=false;
        }
    }


}

Game::Game(int tmp[9][9]) {
    win = false;
    for(int i = 0 ; i < 9; i++){
        for(int j = 0; j < 9; j++){
            tomb[i][j] = tmp[i][j];
            if(tmp[i][j] == 0)
                matrix[i][j]=false;
            else
                matrix[i][j]=true;
        }
    }
}

bool Game::step(int x, int y, int num) {

    if(matrix[x][y] || num < 1 || num > 9)
        return false;


    tomb[x][y] = num;

    check();
    return true;
}

void Game::check() {

    for(int i = 0; i < valid.size();i++) {
        for(int j = 0; j < valid[0].size();j++) {
            valid[i][j] = true;
        }
    }


    vector<int> numbers(10);
    for(int i = 0; i < numbers.size();i++)
        numbers[i] = 0;
    vector<vector<point>> index = vector<vector<point>>(10, vector<point>(0));

    for(int k = 0; k < 9; k++) {

        for(int i = 0;i<tomb.size();i++) {
            numbers[tomb[i][k]]++;
            point p(i,k);
            index[tomb[i][k]].push_back(p);
        }
        for(int i = 1;i < numbers.size();i++) {
            if(numbers[i] > 1) {
                    for(int j = 0;j<index[i].size();j++) {
                        valid[index[i][j].x][index[i][j].y ] = false;
                    }
            }
        }

        for(int i = 0; i < numbers.size();i++)
            numbers[i] = 0;

        for(int i = 0; i < index.size();i++)
            index[i].clear();


    }


    for(int k = 0; k < 9; k++) {

        for(int i = 0;i<tomb.size();i++) {
            numbers[tomb[k][i]]++;
            point p(k,i);
            index[tomb[k][i]].push_back(p);
        }
        for(int i = 1;i < numbers.size();i++) {
            if(numbers[i] > 1) {
                    for(int j = 0;j<index[i].size();j++) {
                        valid[index[i][j].x][index[i][j].y ] = false;
                    }
            }
        }

        for(int i = 0; i < numbers.size();i++)
            numbers[i] = 0;

        for(int i = 0; i < index.size();i++)
            index[i].clear();

    }


    for(int i = 0; i < 9; i += 3 ) {
        for(int j = 0; j < 9; j += 3 ) {

            for(int x = i; x < i+3; x++ ) {
                for(int y = j; y < j+3; y++ ) {

                    numbers[tomb[x][y]]++;
                    point p(x,y);
                    index[tomb[x][y]].push_back(p);


                }
            }

            for(int i = 1;i < numbers.size();i++) {
                if(numbers[i] > 1) {
                        for(int j = 0;j<index[i].size();j++) {
                            valid[index[i][j].x][index[i][j].y ] = false;
                        }
                }
            }

            for(int i = 0; i < numbers.size();i++)
                numbers[i] = 0;

            for(int i = 0; i < index.size();i++)
                index[i].clear();

        }
    }


    for(int x = 0; x < 9; x++ ) {
        for(int y = 0; y < 9; y++ ) {
            if(tomb[x][y] == 0 || !valid[x][y])
                return;
        }
    }

    win = true;
    return;

}

bool Game::isWin() {
    return win;
}

vector<vector<int>> Game::getNumbers() {
    return tomb;
}
vector<vector<bool>> Game::getBaseNumbers() {
    return matrix;
}
vector<vector<bool>> Game::getValidNumbers() {
    return valid;
}


