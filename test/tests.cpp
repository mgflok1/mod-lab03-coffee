// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialState) {
    Automata vendingMachine;
    EXPECT_EQ(vendingMachine.getState(), OFF);
}

TEST(AutomataTest, TurnOn) {
    Automata vendingMachine;
    vendingMachine.on();
    EXPECT_EQ(vendingMachine.getState(), WAIT);
}

TEST(AutomataTest, AddCoin) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(10);
    EXPECT_EQ(vendingMachine.getState(), WAIT);
}

TEST(AutomataTest, GetMenu) {
    Automata vendingMachine;
    std::vector<std::string> menu = {"Coffee", "Tea"};
    std::vector<int> prices = {10, 5};
    vendingMachine.getMenu(menu, prices);
}

TEST(AutomataTest, ChoiceAndCheck) {
    Automata vendingMachine;
    vendingMachine.on();
    std::vector<std::string> menu = {"Coffee", "Tea"};
    std::vector<int> prices = {10, 5};
    vendingMachine.getMenu(menu, prices);
    vendingMachine.coin(15);
    vendingMachine.choice(0);
    EXPECT_TRUE(vendingMachine.check(0));
}

TEST(AutomataTest, Cancel) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(10);
    vendingMachine.cancel();
    EXPECT_EQ(vendingMachine.getState(), WAIT);
}

TEST(AutomataTest, CookAndFinish) {
    Automata vendingMachine;
    vendingMachine.on();
    std::vector<std::string> menu = {"Coffee"};
    std::vector<int> prices = {10};
    vendingMachine.getMenu(menu, prices);
    vendingMachine.coin(15);
    vendingMachine.choice(0);
    vendingMachine.check(0);
    vendingMachine.cook();
    vendingMachine.finish();
    EXPECT_EQ(vendingMachine.getState(), WAIT);
}
