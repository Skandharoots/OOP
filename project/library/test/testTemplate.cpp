//
// Created by Marek Kopania on 24/01/2023.
//
#include <boost/test/unit_test.hpp>

#include "client.h"
#include "room.h"
#include "empty.h"
#include "basic.h"
#include "equipped.h"
#include "card.h"
#include "black.h"
#include "platinum.h"
#include <memory>
#include "trainer.h"
#include "humanresources.h"

BOOST_AUTO_TEST_SUITE(GymTestSuite)

BOOST_AUTO_TEST_CASE(testCreationOfHrAndSubclasses) {

        std::shared_ptr<HumanResources> h = std::make_shared<HumanResources>();
        h->createClient("Juan", 1000.00, "Gold");
        h->createClient("Antonio", 22000.00, "Platinum");
        h->createClient("Rodrigo", 2400.00, "Black");
        h->createTrainer("Dzik", 100.00);
        h->createTrainer("Biggest Dzik", 1000.00);
        h->createTrainer("Medium Dzik", 1500.00);
        h->createRoom(empty);
        h->createRoom(equipped);
        h->createRoom(equipped);
        h->createRoom(basic);
        h->createRoom(equipped);
        BOOST_REQUIRE_EQUAL(h->getClient(2)->getName(), "Antonio");
        BOOST_REQUIRE_EQUAL(h->getRoom(4)->getName(), "Basic");
        BOOST_REQUIRE_EQUAL(h->getRoom(5)->getCost(), 50.00);
        BOOST_REQUIRE_EQUAL(h->getTrainer(2)->getCost(), 1000.00);
        BOOST_REQUIRE_EQUAL(h->getTrainer(3)->getName(), "Medium Dzik");
}

BOOST_AUTO_TEST_CASE(testCreationOfHrAndOperationsBetweenClientAndTrainer) {
        std::shared_ptr<HumanResources> h = std::make_shared<HumanResources>();
        h->createClient("Juan", 100.00, "Gold");
        h->createClient("Antonio", 22000.00, "Platinum");
        h->createClient("Rodrigo", 2400.00, "Black");
        h->createTrainer("Dzik", 100.00);
        h->createTrainer("Biggest Dzik", 1000.00);
        h->createTrainer("Medium Dzik", 1500.00);
        h->createRoom(empty);
        h->createRoom(equipped);
        h->createRoom(equipped);
        h->createRoom(basic);
        h->createRoom(equipped);
        h->getClient(1)->addRoom(h->getRoom(3));
        //Check if room got added to client and is in a correct place on the stack in hr
        BOOST_REQUIRE_EQUAL(h->getClient(1)->getRoomCost(), 50.00);
        BOOST_REQUIRE_EQUAL(h->getRoom(3)->getName(), "Equipped");
        //Check if the client has been trained and cost been drawn from balance
        h->getTrainer(2)->train(h->getClient(2));
        h->getClient(2)->payForTraining(h->getTrainer(2));
        BOOST_REQUIRE_EQUAL(h->getClient(2)->getBalance(), 21000.00);
        //Check if discount card works
        h->getClient(2)->setBalance(22000);
        h->getClient(2)->useDiscount(h->getTrainer(2));
        h->getTrainer(2)->train(h->getClient(2));
        h->getClient(2)->payForTraining(h->getTrainer(2));
        BOOST_TEST(h->getClient(2)->getBalance() > 20500.00);
        //Check if trainer paid the HR and got profit from income
        h->getTrainer(2)->payHumanResources(h);
        BOOST_TEST(h->getTrainer(2)->getProfit() > 0.00);
        BOOST_TEST(h->getIncome() > 0.00);
        //Check if rooms have been correctly added to a client
        h->getClient(3)->addRoom(h->getRoom(2));
        h->getClient(3)->addRoom(h->getRoom(5));
        h->getClient(3)->addRoom(h->getRoom(3));
        BOOST_REQUIRE_EQUAL(h->getClient(3)->getRoomCost(), 150.00);
        //Check if room was dropped and if HR got the money for rooms
        h->getClient(3)->dropRoom(2);
        h->getClient(3)->payForRooms(h);
        BOOST_REQUIRE_EQUAL(h->getClient(3)->getRoomCost(), 100.00);
        BOOST_TEST(h->getIncome() != 0);
}
    BOOST_AUTO_TEST_CASE(testCreationOfClient) {
        std::shared_ptr<Client> c = std::make_shared<Client>("Jason", 100.00);
        std::shared_ptr<Room> r1 = std::make_shared<Empty>();
        std::shared_ptr<Room> r2 = std::make_shared<Equipped>();
        std::shared_ptr<Room> r3 = std::make_shared<Equipped>();
        c->addRoom(r1);
        c->addRoom(r3);
        BOOST_REQUIRE_EQUAL(c->getName(), "Jason");
        BOOST_REQUIRE_EQUAL(c->getBalance(), 100.00);
        BOOST_REQUIRE_EQUAL(c->getRoomCost(), 70.00);
        c->addRoom(r2);
        BOOST_REQUIRE_EQUAL(c->getRoomCost(), 70.00);
    }
    BOOST_AUTO_TEST_CASE(testTrainingScenarios) {
        std::shared_ptr<Client> c = std::make_shared<Client>("Jason", 100.00);
        std::shared_ptr<Trainer> t = std::make_shared<Trainer>("Jackson", 40.00);
        std::shared_ptr<Card> card = std::make_shared<Black>();
        t->train(c);
        c->payForTraining(t);
        BOOST_REQUIRE_EQUAL(c->getBalance(), 60.00);
        c->setBalance(40.00);
        double temp = t->getCost();
        c->getDiscount(card);
        c->useDiscount(t);
        BOOST_TEST(t->getCost() < 40.00);
        t->train(c);
        c->payForTraining(t);
        BOOST_REQUIRE_EQUAL(c->getBalance(), 100.00 - (temp - (temp * 10 / 100)));
        BOOST_TEST(t->getIncome() != 0.00);
        t->setCost(temp);
        BOOST_REQUIRE_EQUAL(t->getCost(), 40.00);
    }
BOOST_AUTO_TEST_SUITE_END()