// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    // sanity checks
    assert(i > 0);
    assert(j > 0);
    
    // define max length=1 in case input is 1
    int max_length = 1;
    
    // if i is greater than j, swap them
    if (i > j) {
        int temp = j;
        j = i;
        i = temp;
    }
    assert(i <= j);
    
    // check all numbers between i and j
    for (int k = i; k <=j; ++k) {
        int length = 1;
        int val = k;
        // compute sequence length
        while (val > 1) {
            if (( val % 2) == 0) {
                val = val/2;
            }
            else {
                val = val * 3 + 1;
            }
            ++length;
        }
        // now check if length is greater than max_length
        // if so, update value of max_length
        if (length > max_length) {
            max_length = length;
        }
    }
    assert (max_length >= 1); 
    return max_length;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
