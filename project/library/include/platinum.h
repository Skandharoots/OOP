//
// Created by Marek Kopania on 11/01/2023.
//

#ifndef PROJECT_PLATINUM_H
#define PROJECT_PLATINUM_H

#include "card.h"

class Platinum : public Card {
public:
    Platinum();
    virtual ~Platinum();
    void addDiscount(Trainer& trainer);
};
#endif //PROJECT_PLATINUM_H
