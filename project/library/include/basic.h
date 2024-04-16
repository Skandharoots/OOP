//
// Created by Marek Kopania on 11/01/2023.
//
#include "room.h"

#ifndef PROJECT_BASIC_H
#define PROJECT_BASIC_H

class Basic : public Room {
public:
    Basic();
    virtual ~Basic();
    double getCost();
    std::string getName();
};

#endif //PROJECT_BASIC_H
