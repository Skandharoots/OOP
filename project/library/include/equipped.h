//
// Created by Marek Kopania on 11/01/2023.
//
#include "room.h"

#ifndef PROJECT_EQUIPPED_H
#define PROJECT_EQUIPPED_H

class Equipped : public Room {
public:
    Equipped();
    virtual ~Equipped();
    double getCost();
    std::string getName();
};

#endif //PROJECT_EQUIPPED_H
