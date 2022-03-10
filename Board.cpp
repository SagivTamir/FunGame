//
// Created by tamir on 06/03/2022.
//

#include <iostream>
#include "Board.h"

bool Board::isValidIndices(int row, int col) const {
    return row >= 0 && row < length && col >= 0 && col < width;
}

bool Board::isGameFinished(PLAYER_IDENTITY *winner_identity) const {
    if (winner_identity == nullptr) {return false;}
    if (dummyNodeLastRow.getRootIndices() == dummyNodeFirstRow.getRootIndices()){
        // player_1 wins
        *winner_identity = PLAYER_1;
        return true;
    }
    if (dummyNodeLastCol.getRootIndices() == dummyNodeFirstCol.getRootIndices()){
        // player_2 wins
        *winner_identity = PLAYER_2;
        return true;
    }
    return false;
}

Board::Board(int width, int length) :
    width(width),
    length(length),
    board_vec(width, std::vector<SquareNode> (length)),
    dummyNodeFirstRow(-1, 0, PLAYER_1),
    dummyNodeLastRow(-1, length - 1, PLAYER_1),
    dummyNodeFirstCol(0, -1, PLAYER_2),
    dummyNodeLastCol(width - 1, -1 , PLAYER_2)
{
    for (int col = 0; col < width; col++){
        for (int row = 0; row < length; row++){
            board_vec[col][row].setIndices(row,col);
            board_vec[col][row].setRootByIndices(row,col);
        }
    }

}

void Board::BoardMakeAMove(int first_index, int second_index, PLAYER_IDENTITY current_player) {
    int row = first_index;
    int col = second_index;
    if (!isValidIndices(row, col)) {
        // throw OutOfRange;
        return;
    }
    if (!(board_vec[col][row].isNodeEmpty())) {
        // throw AlreadyTaken;
        return;
        }
    (board_vec[col][row]).setIdentity(current_player);
    connectWithDummyNodes(board_vec[col][row]);
    std::vector<Grid> neighbors_places = getNeighborsToUniteWith(first_index, second_index, current_player);
    int neighbor_col, neighbor_row;
    for (auto &neighbors_place : neighbors_places) {
        neighbor_row = neighbors_place.getFirstIndex();
        neighbor_col = neighbors_place.getSecondIndex();
        unite(board_vec[col][row], board_vec[neighbor_col][neighbor_row]);
    }
}


void Board::connectWithDummyNodes(SquareNode& node){
    if (node.getIdentity() == PLAYER_1)
    {
        if (node.getNodeIndices().getFirstIndex() == 0){
//            unite(node,dummyNodeFirstRow);
            node.setRootByGrid(dummyNodeFirstRow.getNodeIndices());
        }
        if (node.getNodeIndices().getFirstIndex() == length - 1)
        {
//            unite(node,dummyNodeLastRow);
            node.setRootByGrid(dummyNodeLastRow.getNodeIndices());
        }
    }
    if (node.getIdentity() == PLAYER_2)
    {
        if (node.getNodeIndices().getSecondIndex() == 0){
//            unite(node,dummyNodeFirstCol);
            node.setRootByGrid(dummyNodeFirstCol.getNodeIndices());
        }
        if (node.getNodeIndices().getSecondIndex() == width - 1)
        {
//            unite(node,dummyNodeLastCol);
            node.setRootByGrid(dummyNodeLastCol.getNodeIndices());

        }
    }

}

std::vector<Grid> Board::getNeighborsToUniteWith(int first_index, int second_index, PLAYER_IDENTITY current_player) const {
    std::vector<Grid> neighbors;
    // i and j range's is for check diagonals-neighbors too.
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0){ //node is a neighbor with himself
                continue;
            }
            if (isValidNeighbor(first_index + i, second_index + j, current_player))
            {
                Grid new_neighbor(first_index + i, second_index + j);
                neighbors.push_back(new_neighbor);
            }
        }
    }
    return neighbors;
}

bool Board::isValidNeighbor(int first_index, int second_index, PLAYER_IDENTITY identity) const {
    if (isValidIndices(first_index,second_index)){
        if ((board_vec[second_index][first_index]).getIdentity() == identity)
        {
            return true;
        }
    }
    return false;
}

void Board::unite(SquareNode &first_node, SquareNode &second_node){
    SquareNode& first_root = find(first_node);
    SquareNode& second_root = find(second_node);
    if (first_root.getRootIndices() == second_root.getRootIndices()) // same root, already united
    {
        return;
    }
    if (first_root.getNumOfNodesInTree() >= second_root.getNumOfNodesInTree()){
        second_root.setRootByGrid(first_root.getRootIndices());
        second_root.setNumOfNodesInTree(second_root.getNumOfNodesInTree() + first_root.getNumOfNodesInTree());
    }
    else{
        first_root.setRootByGrid(second_root.getRootIndices());
        first_root.setNumOfNodesInTree(first_root.getNumOfNodesInTree() + second_root.getNumOfNodesInTree());
    }
}

SquareNode& Board::find(SquareNode &node) {
    SquareNode current_node = node;
    Grid current_indices = node.getNodeIndices();
    while (current_node.getRootIndices() != current_node.getNodeIndices())
    {
        current_indices = current_node.getRootIndices();
        if (isDummyNodeIndices(current_indices)){
            break;
        }
        current_node = board_vec[current_indices.getSecondIndex()][current_indices.getFirstIndex()];
    }
//    SquareNode root = node;
    SquareNode root = current_node;
    current_node = node;
    SquareNode prev;
    current_indices = current_node.getNodeIndices();
    while (current_node.getRootIndices() != current_node.getNodeIndices())
    {
        prev = current_node;
        current_indices = current_node.getRootIndices();
        if (isDummyNodeIndices(current_indices)){
            return getDummyNode(current_indices);
        }
        current_node = board_vec[current_indices.getSecondIndex()][current_indices.getFirstIndex()];
        prev.setRootByGrid(root.getRootIndices());
    }
    return board_vec[root.getRootIndices().getSecondIndex()][root.getRootIndices().getFirstIndex()];
}

bool Board::isDummyNodeIndices(Grid &node_indices) const {

    return (node_indices == dummyNodeFirstRow.getNodeIndices() ||
            node_indices == dummyNodeLastRow.getNodeIndices() ||
            node_indices == dummyNodeLastRow.getNodeIndices() ||
            node_indices == dummyNodeFirstCol.getNodeIndices() ||
            node_indices == dummyNodeLastCol.getNodeIndices());
}

int Board::getWidth() const{
    return width;
}

int Board::getLength() const{
    return length;
}


//void Board::printBoard() const {
//    for (int row = 0; row < length; row++){
//        for (int col = 0; col < width; col++){
//            std::cout << "|" << board_vec[col][row].getIdentity() << "|";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//}

void Board::printBoard() const {
    for (int row = 0; row < length; row++){
        for (int col = 0; col < width; col++){
            std::cout << "|" << board_vec[col][row].getIdentity() << "|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int row = 0; row < length; row++){
        for (int col = 0; col < width; col++){
            Grid current_grid = (board_vec[col][row]).getRootIndices();
            if (isDummyNodeIndices(current_grid))
            {
               printDummy(current_grid);
            }
            else
            {
                std::cout << "|" << current_grid.getFirstIndex() << "," << current_grid.getSecondIndex() << "|";
            }

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;
}

SquareNode &Board::getDummyNode(Grid &current_grid) {
    if (current_grid.getFirstIndex() == -1){
        if (current_grid.getSecondIndex() == 0){
            return dummyNodeFirstRow;
        }
        else{
            return dummyNodeLastRow;
        }
    }
    if (current_grid.getSecondIndex() == -1){
        if (current_grid.getFirstIndex() == 0){
            return dummyNodeFirstCol;
        }
        else{
            return dummyNodeLastCol;
        }
    }
    else{
        return dummyNodeLastCol;
    }
}

void Board::printDummy(Grid &node_indices) const{
    if (node_indices == dummyNodeFirstRow.getNodeIndices())
    {
        std::cout << "|" << "FR" << "|";
    }
    if (node_indices == dummyNodeLastRow.getNodeIndices())
    {
        std::cout << "|" << "LR" << "|";
    }
    if (node_indices == dummyNodeFirstCol.getNodeIndices())
    {
        std::cout << "|" << "FC" << "|";
    }
    if (node_indices == dummyNodeLastCol.getNodeIndices())
    {
        std::cout << "|" << "LC" << "|";
    }
}


//dummyNodeFirstRow(-1, 0, PLAYER_1),
//dummyNodeLastRow(-1, length - 1, PLAYER_1),
//dummyNodeFirstCol(0, -1, PLAYER_2),
//dummyNodeLastCol(width - 1, -1 , PLAYER_2)