//
// Created by Marek Kopania on 11/01/2023.
//
#ifndef PROJECT_GOLD_H
#define PROJECT_GOLD_H

#include "card.h"

class Gold : public Card {
public:
    Gold();
    virtual ~Gold();
    void addDiscount(Trainer& trainer);
};
#endif //PROJECT_GOLD_H
