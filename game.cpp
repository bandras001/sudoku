#include "game.hpp"

Game::Game(){
    for(int i = 0 ; i < 9; i++){
        for(int j = 0; j < 9; j++){
            tomb[i][j] = 0;
            matrix[i][j]=false;
        }
    }


}
