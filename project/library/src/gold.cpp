//
// Created by Marek Kopania on 11/01/2023.
//
#include "gold.h"
#include "trainer.h"

Gold::Gold() {

}

Gold::~Gold() {

}

void Gold::addDiscount(Trainer& trainer) {
    double cost = trainer.getCost() - (trainer.getCost() * 20 / 100);
    trainer.setCost(cost);
}

