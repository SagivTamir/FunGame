//
// Created by tamir on 06/03/2022.
//

#include "Game.h"
#include <iostream>


void Game::PlayerMakeAMove(int first_index, int second_index) {
    try{
        board->BoardMakeAMove(first_index - 1,second_index - 1,current_player.getCurrentPlayerTurn());
        printGame();
        if (board->isGameFinished() || isReachedMaxMoves())
        {
            is_game_finished = true;
            return;
        }
        current_player.changePlayerTurn();
        num_of_success_moves++;
    }
    catch(std::bad_alloc& e){
        std::cout << "allocation error occurred" << std::endl;
    }
    catch(OutOfRange& e){
        std::cout << "indices are out of range,"
                     " please choose indices between 1 to " << board->getWidth() << std::endl;
    }
    catch(AlreadyOccupied& e){
        std::cout << "indices are already occupied,"
                     " please choose another indices" << std::endl;
    }
}

Game::Game(int width, int length) :
    current_player(),
    board(new Board(width, length)) ,
    is_game_finished(false),
    num_of_success_moves(0) {}

void Game::printGame() const {
    board->printBoard();
}


bool Game::isGameFinished() const {
    if (is_game_finished)
    {
        std::cout << "the winner is player number " << current_player.getCurrentPlayerTurn() << std::endl;
    }
    return is_game_finished;
}

Game::~Game() {
    delete board;
}

bool Game::isReachedMaxMoves() const {
    return num_of_success_moves == board->getLength() * board->getWidth();
}
