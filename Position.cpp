/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Sonali Pai and Raffy Millado
 * sonpai and rmillado
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include "Position.h"
#include "utility.h"


Position::Position() {
    row = 0;
    col = 0;
}

Position::Position(int row_in, int col_in) {
    row = check_range(row_in);
    col = check_range(col_in);
    
}

Position::Position(char row_in, char col_in) {

    if (col_in > 'a' && col_in < 'z')
        toupper(col_in);
    
    int rowNumber = row_in - 49;
    int columnNumber = col_in - 65;
    row = check_range(rowNumber);
    col = check_range(columnNumber);
}

int Position::get_row() {
    
    return row;
}

void Position::set_row(int row_in) {
    row = check_range(row_in);
    return;
}

int Position::get_col() {
   
    return col;
}

void Position::set_col(int col_in) {
    col = check_range(col_in);
    return;
}

void Position::read(istream &is) {
    char leftP;
    char comma;
    char rightP;
    char column;

    
    is >> row;

    if (is.fail())
    {
        is.clear();
        is >> leftP >> row >> comma >> column >> rightP;
        
    }
    else
    {
        is >> column;
    }
    
    column = toupper(column);
    row = check_range(row - 1);
    col = check_range(column - 65);
 
    return;
}

void Position::write(ostream &os) {
 
    int r1;
    r1 = row + 1;
    
    char c1;
    c1 = col + 65;
    
    os << "(" << r1 << "," << c1 << ")";
   
 
    
    return;
}

int Position::check_range(int val) {
    if (val >= 0 && val <= MAX_GRID_SIZE)
    {
        return val;
    }
    else
    {
        if (val < 0)
        {
            return 0;
        }
        else
        {
            return MAX_GRID_SIZE - 1;
        }
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is,  Position &pos) {
    pos.read(is);
    return is;
}

ostream &operator<<(ostream &os, Position pos) {
    pos.write(os);
    return os;
}



