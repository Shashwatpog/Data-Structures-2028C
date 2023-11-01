#pragma once
#include "Part.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <time.h>
#include <ctime>

using namespace std;

Part::Part(string d, string uom, int sku, int p, int lt)
{
    Desc = d;
    UOM = uom;
    SKU = sku;
    Price = p;
    LeadTime = lt;
    QOH = 0;
};

Part::Part(string d, string uom, int sku, int p, int lt, int qoh)
{
    Desc = d;
    UOM = uom;
    SKU = sku;
    Price = p;
    LeadTime = lt;
    QOH = qoh;
};

Part::Part(Part* CPart)
{
    Desc = CPart->Desc;
    UOM = CPart->UOM;
    SKU = CPart->SKU;
    Price = CPart->Price;
    LeadTime = CPart->LeadTime;
    QOH = CPart->QOH;
}

string Part::GetPartInfo()
{
    return ("SKU: " + to_string(SKU) + " Desc: " + Desc);
}

int Part::GetPrice()
{
    return (Price);
}

int Part::GetSKU()
{
    return (SKU);
}

int Part::GetQOH()
{
    return (QOH);
}

bool Part::InStock()
{
    return (QOH > 0);
}

int Part::rdn(int y, int m, int d)
{ /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    int x = 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
    return x;
}

bool Part::Availaible(string d)
{
    if (QOH > 0)
    {
        return true;
    }

    int day, month;
    size_t pos = 0;
    string delim = "/";

    pos = d.find(delim);
    month = stoi(d.substr(0, pos));
    d.erase(0, pos + delim.length());

    pos = d.find(delim);
    day = stoi(d.substr(0, pos));
    d.erase(0, pos + delim.length());

    time_t t = time(NULL);
    struct tm now;
    localtime_s(&now, &t);

    if ((rdn(123, month, day) - rdn(123, 3, now.tm_mday)) > this->LeadTime)
    {
        return true;
    }

    return false;
}

bool Part::operator>(Part& P)
{
    return (this->SKU > P.SKU);
}

bool Part::operator<(Part& P)
{
    return (this->SKU < P.SKU);
}

bool Part::operator==(Part& P)
{
    return (this->SKU == P.SKU);
}

bool Part::operator!=(Part& P)
{
    return (this->SKU != P.SKU);
}
