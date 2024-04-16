//
// Created by Marek Kopania on 11/01/2023.
//
#include "basic.h"

Basic::Basic() : Room("Basic", 30.00) {

}

Basic::~Basic() {

}

double Basic::getCost() {
    return cost;
}

std::string Basic::getName() {
    return name;
}

