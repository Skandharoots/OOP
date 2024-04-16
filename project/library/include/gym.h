//
// Created by Marek Kopania on 11/01/2023.
//
#ifndef PROJECT_GYM_H
#define PROJECT_GYM_H
#include <memory>
#include "displaymanager.h"
#include "humanresources.h"

class HumanResources;
class DisplayManager;
class Client;
class Trainer;

class Gym{
private:
    std::shared_ptr<HumanResources> HR;
    std::shared_ptr<DisplayManager> DM;
public:
    Gym();
    ~Gym();
    void openGym();
    void readKey(char operation);
    void clientOperation(int client);
    void gymOperations();
};
#endif //PROJECT_GYM_H
