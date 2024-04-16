//
// Created by Marek Kopania on 11/01/2023.
//
#include "client.h"
#include "humanresources.h"
#include <iostream>

std::string Client::getName() {
    return name;
}

void Client::setName(std::string name) {
    this->name = name;
}

void Client::getTrained(double cost) {
    try {
        if (cost <= getBalance()) {
            this->trainingCost += cost;
        } else throw std::logic_error("Not enough money.\n");
    }
    catch(std::logic_error) {
        std::cout << "Not enough money." << std::endl;
    }
}

void Client::getDiscount(std::shared_ptr<Card> card) {
    myCard = card;
}

void Client::useDiscount(std::shared_ptr<Trainer> trainer) {
    try {
        if (myCard != nullptr) {
            myCard->addDiscount(*trainer);
        } else {
            throw std::logic_error("No card!\n");
        }
    }
    catch(std::logic_error) {
        std::cout << "You don't have any card." << std::endl;
    }
}

void Client::setBalance(double balance) {
    this->balance += balance;
}

double Client::getBalance() {
    return balance;
}

void Client::addRoom(std::shared_ptr<Room> room) {
    try {
        if (room->getCost() <= getBalance() - getRoomCost()) {
            rooms.push_back(room);
        } else throw std::logic_error("Not enough money.\n");
    }
    catch(std::logic_error) {
        std::cout << "Not enough money." << std::endl;
    }
}

std::shared_ptr<Room> Client::dropRoom(int position) {
    std::shared_ptr<Room> temp = rooms[position];
    rooms.erase(rooms.begin() + position);
    return temp;
}

double Client::getTrainingCost() {
    return trainingCost;
}

double Client::getRoomCost() {
    double total = 0;
    for(unsigned int i = 0; i < rooms.size(); i++) {
        total += rooms[i]->getCost();
    }
    return total;
}

void Client::payForTraining(std::shared_ptr<Trainer> trainer) {
    try {
        if (getTrainingCost() <= getBalance()) {
            double temp = trainingCost;
            trainingCost = 0;
            balance = balance - temp;
            trainer->getPaid(temp);
        } else throw std::logic_error("Not enough money. \n");
    }
    catch(std::logic_error) {
        std::cout << "Not enough money for training." << std::endl;
    }
}

void Client::payForRooms(std::shared_ptr<HumanResources> hr) {
    try {
        if (getBalance() - getRoomCost() >= 0) {
            balance = balance - getRoomCost();
            hr->getMoneyFromClient(getRoomCost());
        } else throw std::logic_error("Not enough money.\n");
    }
    catch(std::logic_error) {
        std::cout << "Not enough money for rooms." << std::endl;
    }
}


Client::~Client() {}

Client::Client(std::string name, double balance) : name(name), balance(balance) {

}



