//
// Created by Marek Kopania on 11/01/2023.
//

#ifndef PROJECT_CARD_H
#define PROJECT_CARD_H

#include <string>

class Trainer;

class Card{
private:
public:
    virtual void addDiscount(Trainer& trainer) = 0;
};
#endif //PROJECT_CARD_H
