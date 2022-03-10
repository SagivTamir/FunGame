//
// Created by tamir on 06/03/2022.
//

#include "Grid.h"

int Grid::getFirstIndex() const {
    return first_index;
}

int Grid::getSecondIndex() const {
    return second_index;
}

bool operator==(const Grid &first, const Grid &second) {
    return first.first_index == second.first_index && first.second_index == second.second_index;
}
