//
// Created by Marek Kopania on 11/01/2023.
//
#include "equipped.h"

Equipped::Equipped() : Room("Equipped", 50.00) {

}

Equipped::~Equipped() {

}

double Equipped::getCost() {
    return cost;
}

std::string Equipped::getName() {
    return name;
}

