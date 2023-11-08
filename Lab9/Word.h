#pragma once
#ifndef _WORD_
#define _WORD_
#include <string>
#include <iostream>

using namespace std;

class Word
{

private:
    string kword;
    int frequency;

public:
    // Constructor
    Word();
    Word(string w, int f);
    // Destructor
    ~Word();

    // Other methods
    void setWord(string kw);
    void setFreq(int f);

    string getWord();
    int getFreq();

    // operator overloads
    bool operator==(Word w);
    bool operator!=(Word w);
    bool operator>(Word w);
    bool operator<(Word w);
    bool operator>=(Word w);
    bool operator<=(Word w);
    friend ostream& operator<<(ostream& os, Word w);
};

#endif