//
// Created by tamir on 06/03/2022.
//

#ifndef FUNGAME_UNIONFINDSQUARES_H
#define FUNGAME_UNIONFINDSQUARES_H

#include "SquareNode.h"

class UnionFindSquares{
    bool Unite(SquareNode& node,SquareNode& second_node, std::vector<std::vector<SquareNode>>& board_vec);
    static SquareNode& find(SquareNode& node, std::vector<std::vector<SquareNode>>& board_vec) ;
};


#endif //FUNGAME_UNIONFINDSQUARES_H
