//
// Created by Marek Kopania on 11/01/2023.
//
#include "humanresources.h"
#include "trainer.h"
#include "client.h"
#include "basic.h"
#include "empty.h"
#include "equipped.h"
#include "card.h"
#include "black.h"
#include "gold.h"
#include "platinum.h"
#include <iostream>
#include <sstream>

using namespace std;

HumanResources::HumanResources() {

}

HumanResources::~HumanResources() {

}

void HumanResources::createClient(std::string name, double balance, string card) {
    std::shared_ptr<Client> client = std::make_shared<Client>(name, balance);
    if(card == "Black") {
        std::shared_ptr<Card> c = std::make_shared<Black>();
        client->getDiscount(c);
        addClient(client);
    }
    if(card == "Gold") {
        std::shared_ptr<Card> c = std::make_shared<Gold>();
        client->getDiscount(c);
        addClient(client);
    }
    if(card == "Platinum") {
        std::shared_ptr<Card> c = std::make_shared<Platinum>();
        client->getDiscount(c);
        addClient(client);
    }
}

void HumanResources::createTrainer(std::string name, double CostPerMonth) {
    std::shared_ptr<Trainer> trainer = std::make_shared<Trainer>(name, CostPerMonth);
    addTrainer(trainer);
}

void HumanResources::createRoom(roomType type) {
    if(type == empty) {
        std::shared_ptr<Room> room = std::make_shared<Empty>();
        addRoom(room);
    }else if (type == basic) {
        std::shared_ptr<Room> room = std::make_shared<Basic>();
        addRoom(room);
    }
    else if (type == equipped) {
        std::shared_ptr<Room> room = std::make_shared<Equipped>();
        addRoom(room);
    }
    else throw logic_error("Non existent type of room!\n");
}

std::shared_ptr<Client> HumanResources::getClient(int clientId) {
    return clients[clientId - 1];
}

std::shared_ptr<Room> HumanResources::getRoom(int roomId) {
    return rooms[roomId - 1];
}

std::shared_ptr<Trainer> HumanResources::getTrainer(int trainerId) {
    return trainers[trainerId-1];
}

void HumanResources::getMoneyFromTrainer(double pay) {
    income += pay;
}

void HumanResources::getMoneyFromClient(double pay) {
    income += pay;
}

std::shared_ptr<Client> HumanResources::dropClient(int clientId) {
    std::shared_ptr<Client> temp = clients[clientId-1];
    clients.erase(clients.begin() + (clientId-1));
    return temp;
}

std::shared_ptr<Trainer> HumanResources::fireTrainer(int trainerId) {
    std::shared_ptr<Trainer> temp = trainers[trainerId-1];
    trainers.erase(trainers.begin() + (trainerId-1));
    return temp;
}

void HumanResources::displayRooms() {

    int i = 1;
    cout << "********* Rooms *********" << endl;
    for(vector<shared_ptr<Room>>::iterator it = rooms.begin(); it != rooms.end(); it++) {
        stringstream ss;
        ss << "ID[" << i << "] " << "Name:" << (*it)->getName() << " Cost: " << (*it)->getCost() << endl;
        cout << ss.str();
        i++;
    }
}

void HumanResources::displayTrainers() {

    int i = 1;
    cout << "********* Trainers *********" << endl;
    for(vector<shared_ptr<Trainer>>::iterator it = trainers.begin(); it != trainers.end(); it++) {
        stringstream ss;
        ss << "ID[" << i << "] "  << "Name:" << (*it)->getName() << " Cost: " << (*it)->getCost() << " Income: " << (*it)->getIncome() << " Profit: " << (*it)->getProfit() << endl;
        cout << ss.str();
        i++;
    }
}

void HumanResources::displayClients() {

    int i = 1;
    cout << "********* Clients *********" << endl;
    for(vector<shared_ptr<Client>>::iterator it = clients.begin(); it != clients.end(); it++) {
        stringstream ss;
        ss << "ID[" << i << "] " << "Name:" << (*it)->getName() << " Balance: " << (*it)->getBalance() << " Training cost: " << (*it)->getTrainingCost() << endl;
        cout << ss.str();
        i++;
    }
}

void HumanResources::addClient(std::shared_ptr<Client> client) {
    clients.push_back(client);
}

void HumanResources::addTrainer(std::shared_ptr<Trainer> trainer) {
    trainers.push_back(trainer);
}

void HumanResources::addRoom(std::shared_ptr<Room> room) {
    rooms.push_back(room);
}

double HumanResources::getIncome() {
    return income;
}

int HumanResources::getClientsSize() {
    return clients.size();
}

int HumanResources::getTrainersSize() {
    return trainers.size();
}

int HumanResources::getRoomsSize() {
    return rooms.size();
}



