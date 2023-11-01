#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Wheel.h"

class Player {
private:
    int money;
    Wheel wheel;

public:
    Player();
    void setMoney(int initialMoney);
    int getMoney() const;
    int spinWheel();
};

#endif
