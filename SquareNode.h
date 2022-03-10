//
// Created by tamir on 06/03/2022.
//

#ifndef FUNGAME_SQUARENODE_H
#define FUNGAME_SQUARENODE_H


#include "PlayerIdentity.h"
#include "Grid.h"
#include "Enums.h"

class SquareNode{
private:
    int BIG_NUMBER = 3000; // for dummy node
    PLAYER_IDENTITY is_owned_by;
    Grid node_place;
    Grid root;
    int num_of_nodes_in_tree; // this for UF unite by size of two groups.

public:
    SquareNode(int first_index,int second_index, PLAYER_IDENTITY is_owned_by = EMPTY) :
    is_owned_by(is_owned_by),
    node_place(first_index,second_index),
    root(first_index,second_index),
    num_of_nodes_in_tree(BIG_NUMBER){}; // only used for dummy nodes
    SquareNode() :
            is_owned_by(EMPTY),
            node_place(-1,-1),
            root(-1,-1),
            num_of_nodes_in_tree(1){};

    void setRootByGrid(Grid new_root);
    void setIndices(int first_index, int second_index);
    void setRootByIndices(int first_index, int second_index);
    void setNumOfNodesInTree(int new_num);
    int getNumOfNodesInTree() const;
    bool isNodeEmpty() const;
    void setIdentity(PLAYER_IDENTITY player);
    PLAYER_IDENTITY getIdentity() const;
    Grid& getRootIndices();

    Grid& getNodeIndices();
    Grid getNodeIndices() const;
    Grid getRootIndices() const;



};
#endif //FUNGAME_SQUARENODE_H
