#pragma once
#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
protected:
    int minValue;
    int maxValue;

public:
    Wheel(int minVal = 1, int maxVal = 10);
    void setRange(int minVal, int maxVal);
    int spin();
    int getMinValue() const;
    int getMaxValue() const;
};

#endif
