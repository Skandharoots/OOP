//
// Created by Marek Kopania on 11/01/2023.
//

#ifndef PROJECT_TRAINER_H
#define PROJECT_TRAINER_H
#include <string>
#include <stdexcept>
#include "humanresources.h"

class Client;
class HumanResources;

class Trainer {
    friend class DisplayManager;
private:
    std::string name;
    double costPerMonth;
    double income;
    double profit;
public:
    Trainer(std::string name, double costPerMonth);
    ~Trainer();
    void train (std::shared_ptr<Client> client);
    void getPaid(double pay);
    void payHumanResources(std::shared_ptr<HumanResources> HR);
    std::string getName();
    double getCost();
    void setCost(double cost);
    double getIncome();
    double getProfit();
};
#endif //PROJECT_TRAINER_H
