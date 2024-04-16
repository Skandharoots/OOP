//
// Created by Marek Kopania on 11/01/2023.
//
#ifndef PROJECT_DISPLAYMANAGER_H
#define PROJECT_DISPLAYMANAGER_H

#include <string>

class HumanResources;
class Client;
class Trainer;

class DisplayManager {
private:

public:
    DisplayManager();
    ~DisplayManager();
    void displayGym(std::shared_ptr<HumanResources> hr);
    void displayClients(std::shared_ptr<HumanResources> hr);
    void displayTrainers(std::shared_ptr<HumanResources> hr);
    void displayRooms(std::shared_ptr<HumanResources> hr);
    void displayMessage(std::string message);
};
#endif //PROJECT_DISPLAYMANAGER_H
