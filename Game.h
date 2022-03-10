//
// Created by tamir on 06/03/2022.
//

#ifndef FUNGAME_GAME_H
#define FUNGAME_GAME_H

#include "PlayerIdentity.h"
#include "Board.h"
#include <iostream>

class Game{
private:
    PlayerTurn current_player;
    Board board;
    bool is_game_finished;

public:
    Game(int width, int length);
    void PlayerMakeAMove(int first_index, int second_index);
    void printGame() const;
    bool isGameFinished() const;

};



#endif //FUNGAME_GAME_H
