//
// Created by Marek Kopania on 11/01/2023.
//
#include "displaymanager.h"
#include "humanresources.h"
#include <iostream>
#include <memory>
using namespace std;

DisplayManager::DisplayManager() {}

DisplayManager::~DisplayManager() {
}

void DisplayManager::displayGym(std::shared_ptr<HumanResources> hr) {
    cout << "************ Welcome to our gym. ************" << endl;
    cout << "Please take a quick look at our clients, trainers and available rooms below." << endl << endl;
    displayClients(hr);
    displayTrainers(hr);
    displayRooms(hr);
    cout << endl;
    cout << "F - to register new client" << endl;
    cout << "E - to manage existing client" << endl;
    cout << "D - to fire a trainer" << endl;
    cout << "C - to unregister a client" << endl;
    cout << "B - to build a new room" << endl;
    cout << "A - to hire a trainer" << endl;
    cout << "Q - to exit the gym" << endl;

}

void DisplayManager::displayClients(std::shared_ptr<HumanResources> hr) {
    hr->displayClients();
}

void DisplayManager::displayTrainers(std::shared_ptr<HumanResources> hr) {
    hr->displayTrainers();
}

void DisplayManager::displayRooms(std::shared_ptr<HumanResources> hr) {
    hr->displayRooms();
}

void DisplayManager::displayMessage(std::string message) {
    cout << endl << message << endl << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
}

