#include "HardModeWheel.h"
#include <cstdlib>
#include <ctime>


HardModeWheel::HardModeWheel(int playerMaxVal) : playerMaxValue(playerMaxVal), consecutivePlayerWins(0) {
    baseRange = playerMaxVal;
    setRange(1, playerMaxValue);
}

int HardModeWheel::spin(int playerResult) {
    if (playerResult != -1) {
        if (playerResult > maxValue) {
            int newMaxValue = playerResult;
            if (newMaxValue < playerMaxValue)
                newMaxValue = playerMaxValue;
            setRange(1, newMaxValue);
            consecutivePlayerWins = 0;
        }
        else if (playerResult < maxValue) {
            consecutivePlayerWins++;
            if (consecutivePlayerWins == 2) { // Decrease the range to 1-10
                setRange(1, 10);
            }
            else if (consecutivePlayerWins == 4) { //decrease the range to 1-5
                setRange(1, 5);
                consecutivePlayerWins = 0; 
            }
        }
        else {
            consecutivePlayerWins = 0; 
        }
    }

    return std::rand() % (maxValue - minValue + 1) + minValue;
}
