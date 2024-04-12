// Copyright 2020 GHA Test Team

#include "Automata.h"

int main() {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.coin(10);
    vendingMachine.coin(5);
    vendingMachine.getMenu({"Coffee", "Tea"}, {10, 5});
    vendingMachine.choice(0);
    vendingMachine.check(0);
    vendingMachine.finish();

    return 0;
}
