//
// Created by tamir on 06/03/2022.
//

#include "Game.h"
#include <iostream>


void Game::PlayerMakeAMove(int first_index, int second_index) {
    try{
        board.BoardMakeAMove(first_index - 1,second_index - 1,current_player.getCurrentPlayerTurn());
    }
    catch(...){
        // add exceptions
    }
    printGame();
    PLAYER_IDENTITY winner = EMPTY;
    if (board.isGameFinished(&winner))
    {
        is_game_finished = true;
        return;
    }
    current_player.changePlayerTurn();
}

Game::Game(int width, int length) : current_player(), board(width, length), is_game_finished(false) {}

void Game::printGame() const {
    board.printBoard();
}


bool Game::isGameFinished() const {
    if (is_game_finished)
    {
        std::cout << "the winner is player number " << current_player.getCurrentPlayerTurn() << std::endl;
    }
    return is_game_finished;
}
