#pragma once
#include "task2.h"
#include "task2.cpp"
#include "task3.h"
#include "task3.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    vector<int> rVector = {};
    vector<int> eVector = {};
    MiddleOrderedList<int> MList = MiddleOrderedList<int>();
    OrderedList<int> OList = OrderedList<int>();
    SpacedOrderedList<int> SList = SpacedOrderedList<int>();
    int numCheck = 0;
    int x, y, z;

    for (int i = 0; i < 100; i++)
    {
        
        for (int i = 0; i < 25; i++)
        {
            rVector.push_back((rand() % 101)); 
        }

        while (!rVector.empty() || !eVector.empty())
        {
            if (!eVector.empty()) 
            {
                if (((rand() % 20) + 1) > 10 && !rVector.empty() && !MList.isFull() && !OList.isFull() && !SList.isFull())
                { 
                    numCheck = (rand() % rVector.size());
                    MList.addItem(rVector[numCheck]);
                    OList.addItem(rVector[numCheck]);
                    SList.addItem(rVector[numCheck]);
                    
                    eVector.push_back(rVector[numCheck]);
                    swap(rVector[numCheck], rVector.back());
                    rVector.pop_back();
                }
                else 
                {
                    numCheck = (rand() % eVector.size());
                    y = MList.removeItem(eVector[numCheck]);
                    x = OList.removeItem(eVector[numCheck]);
                    z = SList.removeItem(eVector[numCheck]);
                    
                    swap(eVector[numCheck], eVector.back());
                    eVector.pop_back();
                }
            }
            else
            {
                numCheck = (rand() % rVector.size());
                MList.addItem(rVector[numCheck]);
                OList.addItem(rVector[numCheck]);
                SList.addItem(rVector[numCheck]);
               
                eVector.push_back(rVector[numCheck]);
                swap(rVector[numCheck], rVector.back());
                rVector.pop_back();
            }
        }

        OList.MakeEmpty();
        MList.MakeEmpty();
        SList.MakeEmpty();
    }

    cout << "OrderedList Stats: " << endl;
    cout << OList.PrintStats() << endl
        << endl;
    cout << "MiddleOrderedList Stats: " << endl;
    cout << MList.PrintStats() << endl
        << endl;
    cout << "SpacedOrderedList Stats: " << endl;
    cout << SList.PrintStats() << endl
        << endl;
}