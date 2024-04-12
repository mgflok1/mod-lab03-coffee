// Copyright 2022 GHA Test Team

#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    state = WAIT;
    std::cout << "Автомат в ожидании\n";
}

void Automata::off() {
    state = OFF;
    std::cout << "Автомат выключен\n";
}

int Automata::getCash() {
    return cash;
}

void Automata::coin(int money) {
    cash += money;
    std::cout << "Добавлено " << money << " рублей. ";
    std::cout <<  "Текущий баланс " << cash << "\n";
}

void Automata::getMenu(const std::vector<std::string>& menu,
const std::vector<int>& prices) {
    this->menu = menu;
    this->prices = prices;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int option) {
    if (option >= 0 && option < menu.size()) {
        state = CHECK;
        std::cout << "Выбрано: " << menu[option];
        std::cout << ". Пожалуйста, подождите, пока пройдет проверка\n";
    } else {
        std::cout << "Invalid option.\n";
    }
}

bool Automata::check(int option) {
    if (cash >= prices[option]) {
        state = COOK;
        std::cout << "Денег достаточно. " << menu[option] << " готовится\n";
        return true;
    } else {
        std::cout << "Не хватает денег, пополните баланк\n";
        return false;
    }
}

void Automata::cancel() {
    cash = 0;
    state = WAIT;
    std::cout << "Транзация отменена.\n";
}

void Automata::cook() {
    std::cout << "Напиток готов\n";
    cash -= prices[0];
    state = WAIT;
}

void Automata::finish() {
    cash = 0;
    state = WAIT;
    std::cout << "Транзакция завершена\n";
}

