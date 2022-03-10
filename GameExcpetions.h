//
// Created by tamir on 08/03/2022.
//

#ifndef FUNGAME_GAMEEXCPETIONS_H
#define FUNGAME_GAMEEXCPETIONS_H

class GameExceptions : public std::exception{
    class InvalidIndices : public GameExceptions{
    public:
        InvalidIndices() = default;
    };
};
#endif //FUNGAME_GAMEEXCPETIONS_H
