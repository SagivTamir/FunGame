//
// Created by tamir on 06/03/2022.
//

#ifndef FUNGAME_BOARD_H
#define FUNGAME_BOARD_H

#include <vector>
#include "PlayerIdentity.h"
#include "SquareNode.h"
#include "Exceptions.h"

class Board{
private:
    int width;
    int length;
    std::vector<std::vector<SquareNode>> board_vec;
    SquareNode dummyNodeFirstRow;
    SquareNode dummyNodeLastRow;
    SquareNode dummyNodeFirstCol;
    SquareNode dummyNodeLastCol;

    bool isValidIndices(int first_index, int second_index) const;
    std::vector<Grid> getNeighborsToUniteWith(int first_index, int second_index, PLAYER_IDENTITY current_player) const;
    bool isDummyNodeIndices(Grid& node_indices) const;
public:

    Board(int width, int length);
    void BoardMakeAMove(int first_index, int second_index, PLAYER_IDENTITY current_player);
    bool isValidNeighbor(int first_index, int second_index, PLAYER_IDENTITY identity) const;
    void printBoard() const;
    void unite(SquareNode& first_node,SquareNode& second_node);
    SquareNode& find(SquareNode& node);
    int getWidth() const;
    int getLength() const;
    void connectWithDummyNodes(SquareNode& node);
    SquareNode& getDummyNode(Grid& current_grid);
    bool isGameFinished() const;
    void printDummy(Grid& node_indices) const;

};



#endif //FUNGAME_BOARD_H
