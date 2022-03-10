//
// Created by tamir on 06/03/2022.
//

#include <vector>
#include "UnionFindSquares.h"
#include "Board.h"

bool UnionFindSquares::Unite(SquareNode &first_node, SquareNode &second_node, std::vector<std::vector<SquareNode>>& board_vec) {
    SquareNode& first_root = find(first_node, board_vec);
    SquareNode& second_root = find(second_node, board_vec);
    if (first_root.getRootIndices() == second_root.getRootIndices()) // same root, already united
    {
        return false;
    }
    if (first_root.getNumOfNodesInTree() >= second_root.getNumOfNodesInTree()){
        second_root.setRootByGrid(first_root.getRootIndices());
        second_root.setNumOfNodesInTree(second_root.getNumOfNodesInTree() + first_root.getNumOfNodesInTree());
    }
    else{
        first_root.setRootByGrid(second_root.getRootIndices());
        first_root.setNumOfNodesInTree(first_root.getNumOfNodesInTree() + second_root.getNumOfNodesInTree());
    }
    return true;
}

SquareNode &UnionFindSquares::find(SquareNode &node, std::vector<std::vector<SquareNode>>& board_vec) {
    SquareNode current_node = node;
    Grid current_indices = node.getNodeIndices();
    while (current_node.getRootIndices() != current_node.getNodeIndices())
    {
        current_indices = current_node.getRootIndices();
        current_node = board_vec[current_indices.getFirstIndex()][current_indices.getSecondIndex()];
    }
    SquareNode root = node;
    SquareNode prev = node;
    current_indices = node.getNodeIndices();
    while (node.getRootIndices() != node.getNodeIndices())
    {
        prev = node;
        current_indices = node.getRootIndices();
        node = board_vec[current_indices.getFirstIndex()][current_indices.getSecondIndex()];
        prev.setRootByGrid(root.getRootIndices());
    }
    return board_vec[root.getRootIndices().getFirstIndex()][root.getRootIndices().getSecondIndex()];
}
