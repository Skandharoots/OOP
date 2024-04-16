//
// Created by Marek Kopania on 11/01/2023.
//
#include "black.h"
#include "trainer.h"
Black::Black() {

}

Black::~Black() {

}

void Black::addDiscount(Trainer& trainer) {
    double cost = trainer.getCost() - (trainer.getCost() * 0.1);
    trainer.setCost(cost);
}

