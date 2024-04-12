// Copyright 2020 GHA Test Team

INCLUDE_AUTOMATA_H_
#define AUTOMATA_H

#include <string>
#include <vector>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
private: 
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;

public: 
    Automata();

    void on();
    void off();
    void coin(int money);
    void getMenu(const std::vector<std::string>& menu, 
const std::vector<int>& prices);
    STATES getState();
    void choice(int option);
    bool check(int option);
    void cancel();
    void cook();
    void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
