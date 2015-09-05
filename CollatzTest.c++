// -------------------------------
// projects/collatz/CollatzTest.c++
// Copyright (C) 2015
// Aishwarya Nagarajan
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout
#include <cassert>  // assert
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair


using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
pair<int, int> collatz_read (const string& s);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (ostream& w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);


// ----
// main
// ----

int main () {
    collatz_solve(cin, cout);
    return 0;}

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
    // define val of max length
    int max_length = 1;
    // check all numners between i and j
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



