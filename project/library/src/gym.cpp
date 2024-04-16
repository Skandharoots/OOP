//
// Created by Marek Kopania on 11/01/2023.
//
#include <stdlib.h>
#include <iostream>
#include "gym.h"
#include "platinum.h"
#include "gold.h"
#include "black.h"
#include "card.h"

using namespace std;

Gym::Gym() {
    HR = make_shared<HumanResources>();
    DM = make_shared<DisplayManager>();
}

Gym::~Gym() {

}

void Gym::openGym() {
    bool quit = false;
    char op;
    HR->createClient("Marek", 800.00, "Platinum");
    HR->createClient("Dominik", 800.00, "Gold");
    HR->createRoom(basic);
    HR->createRoom(equipped);
    HR->createRoom(empty);
    HR->createTrainer("Dzik", 100.00);
    HR->createTrainer("Medium Dzik", 200.00);
    HR->createTrainer("Biggest Dzik", 450.00);
    while(quit == false) {
        cout << endl << endl;
        cout << "To operate on gym type 'O'." << endl;
        cout << "To exit the program type 'Q'." << endl;
        cin >> op;
        switch(op) {
            case 'O':
                gymOperations();
                break;
            case 'Q':
                quit = true;
                break;
            default:
                break;
        }
    }
}

void Gym::readKey(char operation) {
    string name;
    string name1;
    double balance;
    int discID;
    int id1;
    char type, type2;
    double cost;
    bool quit = false;
    switch (operation) {
            case 'F':
                cout << "Enter the name of a new client: " << endl;
                cin.ignore();
                getline(cin, name);
                while(quit == false) {
                    cout << "Enter the balance of a new client: " << endl;
                    cout << "A - 50.00" << endl;
                    cout << "B - 100.00" << endl;
                    cout << "C - 200.00" << endl;
                    cout << "D - 300.00" << endl;
                    cout << "E - 500.00" << endl;
                    cin >> type;
                    switch(type) {
                        case 'A':
                            balance = 50.00;
                            quit = true;
                            break;
                        case 'B':
                            balance = 100.00;
                            quit = true;
                            break;
                        case 'C':
                            balance = 200.00;
                            quit = true;
                            break;
                        case 'D':
                            balance = 300.00;
                            quit = true;
                            break;
                        case 'E':
                            balance = 500.00;
                            quit = true;
                            break;
                        default:
                            quit = false;
                            break;
                    }
                }
                quit = false;
                while(quit == false) {
                    cout << "Select which type of discount card you would like..." << endl;
                    cout << "B - Black card (10%)" << endl;
                    cout << "G - Gold card (20%)" << endl;
                    cout << "P - Platinum card (30%)" << endl;
                    cin >> type2;
                    switch (type2) {
                        case 'B':
                            HR->createClient(name, balance, "Black");
                            quit = true;
                            break;
                        case 'G':
                            HR->createClient(name, balance, "Gold");
                            quit = true;
                            break;
                        case 'P':
                            HR->createClient(name, balance, "Platinum");
                            quit = true;
                            break;
                        default:
                            quit = false;
                            break;
                    }
                }
                cout << endl;
                break;

            case 'E':
                DM->displayClients(HR);
                while(HR->getClientsSize() < id1 or id1 <= 0) {
                    cout << "Select a client ID: ";
                    cin >> id1;
                }
                cout << endl;
                clientOperation(id1);
                break;

            case 'D':
                DM->displayTrainers(HR);
                while(HR->getTrainersSize() < id1 or id1 <= 0) {
                    cout << endl << "Select which trainer to fire: ";
                    cin >> id1;
                    cout << endl;
                }
                HR->fireTrainer(id1);
                break;

            case 'C':
                DM->displayClients(HR);
                while(HR->getClientsSize() < id1 or id1 <= 0) {
                    cout << "Select which client to remove: ";
                    cin >> id1;
                    cout << endl;
                }
                HR->dropClient(id1);
                break;

            case 'B':
                while(quit == false) {
                    cout << "Select the number of one of the types to create a new room:" << endl;
                    cout << "E - Empty" << endl;
                    cout << "B - Basic" << endl;
                    cout << "Q - Equipped" << endl;
                    cin >> type;
                    switch(type) {
                        case 'E':
                            HR->createRoom(empty);
                            quit = true;
                            break;
                        case 'B':
                            HR->createRoom(basic);
                            quit = true;
                            break;
                        case 'Q':
                            HR->createRoom(equipped);
                            quit = true;
                            break;
                        default:
                            cout << "Wrong operation!" << endl;
                            quit = false;
                            break;
                        }
                    }
                break;
            case 'A':
                cout << "Type name of a trainer: ";
                cin.ignore();
                getline(cin, name1);
                cout << endl;
                while(quit == false) {
                    cout << "Give the monthly cost of a trainer: " << endl;
                    cout << "A - 50.00" << endl;
                    cout << "B - 100.00" << endl;
                    cout << "C - 200.00" << endl;
                    cout << "D - 300.00" << endl;
                    cin >> type;
                    switch (type) {
                        case 'A':
                            cost = 50.00;
                            HR->createTrainer(name1, cost);
                            quit = true;
                            break;
                        case 'B':
                            cost = 100.00;
                            HR->createTrainer(name1, cost);
                            quit = true;
                            break;
                        case 'C':
                            cost = 200.00;
                            HR->createTrainer(name1, cost);
                            quit = true;
                            break;
                        case 'D':
                            cost = 300.00;
                            HR->createTrainer(name1, cost);
                            quit = true;
                            break;
                        default:
                            quit = false;
                            break;
                    }
                }
                cout << endl;
                break;
            case 'Q':
                break;
            default:
                break;
        }
    }


void Gym::clientOperation(int client) {

    int id = 0, id2 = 0;
    bool quit = false;
    char op1, op2;
    double temp = 0;
    double money = 0;
    cout << "T - To get trained" << endl;
    cout << "R - To get room" << endl;
    cout << "M - To add money to account" << endl;
    cout << "P - To pay for rooms" << endl;
    cin >> op1;
    switch(op1) {
        case 'T':
            DM->displayTrainers(HR);
            while(HR->getTrainersSize() < id or id <= 0) {
                cout << endl << "Select the ID number of a trainer: ";
                cin >> id;
            }
            while(quit == false) {
                cout << endl << "Would you like to use a discount card? [y/n]" << endl;
                cin >> op2;
                switch (op2) {
                    case 'y':
                        temp = HR->getTrainer(id)->getCost();
                        HR->getClient(client)->useDiscount(HR->getTrainer(id));
                        HR->getTrainer(id)->train(HR->getClient(client));
                        HR->getClient(client)->payForTraining(HR->getTrainer(id));
                        HR->getTrainer(id)->setCost(temp);
                        HR->getTrainer(id)->payHumanResources(HR);
                        quit = true;
                        break;
                    case 'n':
                        HR->getTrainer(id)->train(HR->getClient(client));
                        HR->getClient(client)->payForTraining(HR->getTrainer(id));
                        HR->getTrainer(id)->payHumanResources(HR);
                        quit = true;
                        break;
                    default:
                        cout << "Wrong operation!" << endl;
                        quit = false;
                        break;
                }
            }
                break;
            case 'R':
                DM->displayRooms(HR);
                while(HR->getRoomsSize() < id2 or id2 <= 0) {
                    cout << "Select which room [ID] you would like to rent: ";
                    cin >> id2;
                    cout << endl;
                }
                HR->getClient(client)->addRoom(HR->getRoom(id2));
                break;
        case 'M':
            cout << "Select the amount you wish to add:" << endl;
            cout << "A - 50.00" << endl;
            cout << "B - 100.00" << endl;
            cout << "C - 200.00" << endl;
            cout << "D - 300.00" << endl;
            cout << "E - 500.00" << endl;
            cin >> op2;
            switch(op2) {
                case 'A':
                    HR->getClient(client)->setBalance(50.00);
                    break;
                case 'B':
                    HR->getClient(client)->setBalance(100.00);
                    break;
                case 'C':
                    HR->getClient(client)->setBalance(200.00);
                    break;
                case 'D':
                    HR->getClient(client)->setBalance(300.00);
                    break;
                case 'E':
                    HR->getClient(client)->setBalance(500.00);
                    break;
                default:
                    break;
            }
            break;
        case 'P':
            HR->getClient(client)->payForRooms(HR);
            break;
        default:
            break;
        }
    }

void Gym::gymOperations() {
    bool finalized = false;
    char operate, operate2;
    cout << endl << endl;
    cout << "O - Operate on gym" << endl;
    cout << "I - Display income of the gym" << endl;
    cout << "C - display clients" << endl;
    cout << "T - display trainers" << endl;
    cout << "R - display rooms" << endl;
    cout << "Q - quit operating on gym" << endl;

    cin >> operate;
    while(finalized == false) {
        switch (operate) {
            case 'O':
                DM->displayGym(HR);
                cin >> operate2;
                readKey(operate2);
                finalized = true;
                break;
            case 'C':
                DM->displayClients(HR);
                finalized = true;
                break;
            case 'T':
                DM->displayTrainers(HR);
                finalized = true;
                break;
            case 'R':
                DM->displayRooms(HR);
                finalized = true;
                break;
            case 'I':
                cout << "Income: " << HR->getIncome() << endl;
            case 'Q':
                finalized = true;
                break;
            default:
                break;
        }
    }
}

