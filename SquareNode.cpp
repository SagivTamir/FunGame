//
// Created by tamir on 06/03/2022.
//

#include "SquareNode.h"

void SquareNode::setRootByGrid(Grid new_root) {
    root = new_root;
}

void SquareNode::setNumOfNodesInTree(int new_num) {
    num_of_nodes_in_tree = new_num;
}

int SquareNode::getNumOfNodesInTree() const {
    return num_of_nodes_in_tree;
}

bool SquareNode::isNodeEmpty() const {
    return is_owned_by == EMPTY;
}

void SquareNode::setIdentity(PLAYER_IDENTITY player) {
    is_owned_by = player;
}

Grid& SquareNode::getRootIndices() {
    return root;
}

Grid &SquareNode::getNodeIndices() {
    return node_place;
}

Grid SquareNode::getNodeIndices() const{
    return node_place;
}

PLAYER_IDENTITY SquareNode::getIdentity() const {
    return is_owned_by;
}

void SquareNode::setIndices(int first_index, int second_index) {
    node_place = Grid(first_index,second_index);
}

Grid SquareNode::getRootIndices() const {
    return root;
}

void SquareNode::setRootByIndices(int first_index, int second_index) {
    root = Grid(first_index,second_index);
}
