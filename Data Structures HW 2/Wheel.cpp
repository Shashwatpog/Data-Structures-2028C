#include "Wheel.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Wheel::Wheel(int minVal, int maxVal) : minValue(minVal), maxValue(maxVal) {
    std::srand(std::time(0));
}

void Wheel::setRange(int minVal, int maxVal) {
    minValue = minVal;
    maxValue = maxVal;
}

int Wheel::spin() {
    return std::rand() % (maxValue - minValue + 1) + minValue;
}

int Wheel::getMinValue() const {
    return minValue;
}

int Wheel::getMaxValue() const {
    return maxValue;
}
