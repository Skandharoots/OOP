//
// Created by Marek Kopania on 11/01/2023.
//
#include "platinum.h"
#include "trainer.h"

Platinum::Platinum() {

}

Platinum::~Platinum() {

}

void Platinum::addDiscount(Trainer& trainer) {
    double cost = trainer.getCost() - (trainer.getCost() * 0.3);
    trainer.setCost(cost);
}

