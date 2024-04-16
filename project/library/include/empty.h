//
// Created by Marek Kopania on 11/01/2023.
//
#include "room.h"


#ifndef PROJECT_EMPTY_H
#define PROJECT_EMPTY_H

class Empty : public Room {
public:
    Empty();
    virtual ~Empty();
    double getCost();
    std::string getName();
};

#endif //PROJECT_EMPTY_H
