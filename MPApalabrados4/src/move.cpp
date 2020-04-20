/**
 * @file move.cpp
 * @author DECSAI
 * @note To be implemented by students
 */
#include <string>
#include <cstring>
#include <iostream>
#include <cassert>
#include <stdio.h>

#include "move.h"


using namespace std;

Move:: Move() : row(0), column(0), ishorizontal(false), letters(""), score(0) {}

void Move:: set(int &r, int &c, char &h, const std::string  &l){
    setRow(r);
    setCol(c);
    setHorizontal(h) ;
    setLetters(l) ;
}

void Move:: setRow(int &r){
    assert(r >= 0);
    row = r;
}

void Move:: setCol(int &c){
    assert(c >= 0);
    column = c;
}

void Move:: setHorizontal(char &h){
    if ( h == 'H' || h == 'h')
        ishorizontal = true;
    else
        ishorizontal = false ;
}

void Move:: setLetters(const std::string &l){
    if (l != "@")
        letters = normalizeWord(l);
    else
        letters = l;
}

int Move:: findScore(const Language &l) const {
    int n = 0;
    
    if (!l.query(letters))
        n = -1;
    
    else
        for (int i = 0; i < letters.length(); i++)
            n += l.getScore(letters[i]);
    
    return n;
}

void Move:: setScore(int &s){
    assert(s > -2);
    score = s;
}

int Move:: getScore() const {
    return score;
}

int Move:: getRow() const {
    return row;
}

int Move:: getCol() const {
    return column;
}

bool Move:: isHorizontal() const {
    return ishorizontal;
}

std::string Move:: getLetters() const {
    return toISO(letters);
}

void Move:: print(std::ostream &os) const {

    if (ishorizontal)
        os << "H";
    else
        os << "V";
    
    os << " " << row << " " << column << " " << toUTF(letters) ;
}

void Move:: read(std::istream &is){
    
    char h;
    string l;
    int r, c;

    is >> h ;
    is >> r ;
    is >> c ;
    is >> l;

    set(r, c, h, l) ;
}

bool Move:: equals (const Move &mov) const {
    bool equals = (mov.getLetters()==letters && mov.getCol()==column && mov.getRow()==row && mov.isHorizontal()==ishorizontal);
    return equals;
}