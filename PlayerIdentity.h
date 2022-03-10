//
// Created by tamir on 06/03/2022.
//

#ifndef FUNGAME_PLAYERIDENTITY_H
#define FUNGAME_PLAYERIDENTITY_H

#include "Enums.h"

class PlayerTurn{
public:
private:
    PLAYER_IDENTITY current_player;
public:
    explicit PlayerTurn(PLAYER_IDENTITY player = PLAYER_1);
    void changePlayerTurn();
    PLAYER_IDENTITY getCurrentPlayerTurn() const;
    // operator=
};







#endif //FUNGAME_PLAYERIDENTITY_H
