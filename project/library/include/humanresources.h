//
// Created by Marek Kopania on 11/01/2023.
//
#ifndef PROJECT_HUMANRESOURCES_H
#define PROJECT_HUMANRESOURCES_H

#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "client.h"
#include "room.h"
#include "trainer.h"
#include "card.h"

enum roomType {
    empty,
    basic,
    equipped
};

class HumanResources{
    friend class DisplayManager;
private:
    double income;
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Trainer>> trainers;
    std::vector<std::shared_ptr<Room>> rooms;

public:
    HumanResources();
    ~HumanResources();
    void createClient(std::string name, double balance, std::string card);
    void createTrainer(std::string name, double CostPerMonth);
    void createRoom(roomType type);
    void addClient(std::shared_ptr<Client> client);
    void addTrainer(std::shared_ptr<Trainer> trainer);
    void addRoom(std::shared_ptr<Room> room);
    std::shared_ptr<Client> getClient(int clientId);
    std::shared_ptr<Room> getRoom(int roomId);
    std::shared_ptr<Trainer> getTrainer(int trainerId);
    void getMoneyFromTrainer(double pay);
    void getMoneyFromClient(double pay);
    std::shared_ptr<Client> dropClient(int clientId);
    std::shared_ptr<Trainer> fireTrainer(int trainerId);
    void displayRooms();
    void displayTrainers();
    void displayClients();
    double getIncome();
    int getClientsSize();
    int getTrainersSize();
    int getRoomsSize();
};
#endif //PROJECT_HUMANRESOURCES_H
