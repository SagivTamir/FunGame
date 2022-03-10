//
// Created by tamir on 10/03/2022.
//

#ifndef FUNGAME_EXCEPTIONS_H
#define FUNGAME_EXCEPTIONS_H

class GameExceptions : public std::exception{
};

class OutOfRange : public GameExceptions{
public:
    OutOfRange() = default;
};

class AlreadyOccupied : public GameExceptions{
public:
    AlreadyOccupied() = default;
};





#endif //FUNGAME_EXCEPTIONS_H
