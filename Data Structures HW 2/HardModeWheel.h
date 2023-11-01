#pragma once
#ifndef HARDMODEWHEEL_H
#define HARDMODEWHEEL_H

#include "Wheel.h"

class HardModeWheel : public Wheel {
private:
    int playerMaxValue;
    int consecutivePlayerWins;
    int baseRange;

public:
    HardModeWheel(int playerMaxVal);
    int spin(int playerResult = -1);
};

#endif
