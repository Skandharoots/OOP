//
// Created by Marek Kopania on 18/01/2023.
//

#ifndef PROJECT_LOCAL_CLIENT_H
#define PROJECT_LOCAL_CLIENT_H

#include <string>
#include <vector>
#include <stdexcept>
#include "basic.h"
#include "empty.h"
#include "equipped.h"
#include "room.h"
#include "card.h"
#include "humanresources.h"

class HumanResources;

class Client {
    friend class DisplayManager;
private:
    std::vector<std::shared_ptr<Room>> rooms;
    std::shared_ptr<Card> myCard;

    std::string name;
    double trainingCost;
    double balance;

public:
    Client(std::string name, double balance);
    ~Client();
    std::string getName();
    void setName(std::string name);
    void getTrained(double cost);
    void getDiscount(std::shared_ptr<Card> card);
    void useDiscount(std::shared_ptr<Trainer> trainer);
    double getBalance();
    void setBalance(double balance);
    void addRoom(std::shared_ptr<Room> room);
    std::shared_ptr<Room> dropRoom(int position);
    double getTrainingCost();
    double getRoomCost();
    void payForTraining(std::shared_ptr<Trainer> trainer);
    void payForRooms(std::shared_ptr<HumanResources> hr);
};


#endif //PROJECT_LOCAL_CLIENT_H
