#pragma once
#include "Word.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

Word::Word() {
    kword = "";
    frequency = 0;
}

Word::Word(string w, int f) {
    kword = w;
    frequency = f;
}

Word::~Word()
{

}

void Word::setFreq(int f){
    frequency = f;
}

void Word::setWord(string kw){
    kword = kw;
}

string Word::getWord(){
    return kword;
}

int Word::getFreq(){
    return frequency;
}

bool Word::operator==(Word w){
    return(kword == w.kword);
}

bool Word::operator!=(Word w) {
    return(kword != w.kword);
}

bool Word::operator>(Word w) {
    return(kword > w.kword);
}

bool Word::operator<(Word w) {
    return(kword < w.kword);
}

bool Word::operator>=(Word w) {
    return(kword >= w.kword);
}

bool Word::operator<=(Word w) {
    return(kword <= w.kword);
}

ostream& operator<<(ostream& os, Word w)
{
    os << w.getWord() << " " << w.getFreq();
    return os;
}