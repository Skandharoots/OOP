//
// Created by Marek Kopania on 11/01/2023.
//
#include <string>


#ifndef PROJECT_ROOM_H
#define PROJECT_ROOM_H

class Room {
protected :
    std::string name;
    double cost;
public:
    Room(std::string name, double cost);
    virtual ~Room();
    virtual std::string getName() = 0;
    virtual double getCost() = 0;
};

#endif //PROJECT_ROOM_H
