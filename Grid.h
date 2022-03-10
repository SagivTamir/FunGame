//
// Created by tamir on 06/03/2022.
//

#ifndef FUNGAME_GRID_H
#define FUNGAME_GRID_H

class Grid{
    int first_index;
    int second_index;
public:
    Grid(int first, int second) : first_index(first), second_index(second) {};
    bool operator!=(Grid& second_grid) const{
        return !(operator==(*this,second_grid));
    }

    Grid(const Grid& new_indices){
        first_index = new_indices.first_index;
        second_index = new_indices.second_index;
    }
    int getFirstIndex() const;
    int getSecondIndex() const;
    friend bool operator==(const Grid& first,const Grid& second);

};





#endif //FUNGAME_GRID_H
