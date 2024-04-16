//
// Created by Marek Kopania on 11/01/2023.
//
#include "trainer.h"
#include <iostream>

using namespace std;

Trainer::Trainer(std::string name, double costPerMonth) : name(name), costPerMonth(costPerMonth) {

}
Trainer::~Trainer(){}

void Trainer::train(std::shared_ptr<Client> client) {
    try {
        if (client->getBalance() >= getCost()) {
            client->getTrained(getCost());
        } else {
            throw logic_error("Not enough balance.\n");
        }
    }
    catch(logic_error) {
        cout << "Not enough balance!" << endl;
    }
}

void Trainer::getPaid(double pay) {
    income += pay;
}
void Trainer::payHumanResources (std::shared_ptr<HumanResources> HR) {
    try {
        if (income != 0.0) {
            double pay = getIncome() - (getIncome() * 40 / 100);
            HR->getMoneyFromTrainer(pay);
            profit = getIncome() * 60 / 100;
            income = 0.0;
        } else throw logic_error("You don't have any income.\n");
    }
    catch(logic_error) {
        cout << "You don't have any income." << endl;
    }
}

double Trainer::getCost() {
    return costPerMonth;
}

void Trainer::setCost(double cost) {
    this->costPerMonth = cost;
}

double Trainer::getIncome() {
    return income;
}

double Trainer::getProfit() {
    return profit;
}

string Trainer::getName() {
    return name;
}
