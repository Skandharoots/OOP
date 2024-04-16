//
// Created by Marek Kopania on 11/01/2023.
//
#include "empty.h"

double Empty::getCost() {
    return cost;
}

std::string Empty::getName() {
    return name;
}

Empty::Empty() : Room("Empty", 20.00) {

}

Empty::~Empty() {

}

