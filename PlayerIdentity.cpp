//
// Created by tamir on 06/03/2022.
//
#include "PlayerIdentity.h"

PlayerTurn::PlayerTurn(PLAYER_IDENTITY player){
    if (current_player == PLAYER_1){
        current_player = PLAYER_2;
    }
    else{
        current_player = PLAYER_1;
    }
}

PLAYER_IDENTITY PlayerTurn::getCurrentPlayerTurn() const {
    return current_player;
}

void PlayerTurn::changePlayerTurn() {
    if (current_player == PLAYER_1){
        current_player = PLAYER_2;
    }
    else{
        current_player = PLAYER_1;
    }
}

