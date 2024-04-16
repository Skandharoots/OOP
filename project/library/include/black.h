//
// Created by Marek Kopania on 11/01/2023.
//

#ifndef PROJECT_BLACK_H
#define PROJECT_BLACK_H

#include "card.h"

class Black : public Card {
private:

public:
    Black();
    virtual ~Black();
    void addDiscount(Trainer& trainer);
};
#endif //PROJECT_BLACK_H
