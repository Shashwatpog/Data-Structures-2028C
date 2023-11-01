#pragma once
#ifndef _Part_
#define _Part_

#include <string>
#include <iostream>
using namespace std;

class Part
{
private:
    int SKU;
    int Price;
    int QOH;
    int LeadTime;

    string Desc;
    string UOM;

public:
    // Constructor
    Part(string d, string uom, int sku, int p, int lt);
    Part(Part* CPart);
    Part(string d, string uom, int sku, int p, int lt, int qoh);

    string GetPartInfo();
    int GetPrice();
    int GetSKU();
    int GetQOH();
    int rdn(int y, int m, int d);
    bool InStock();
    bool Availaible(string d);

    bool operator>(Part& P);
    bool operator<(Part& P);
    bool operator==(Part& P);
    bool operator!=(Part& P);

};

#endif