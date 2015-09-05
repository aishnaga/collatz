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
#include <vector>   // for cache

using namespace std;
// Create cache, setting max size to 100K
std::vector<int> cache;
int CACHESIZE = 1000000;

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

// ------------
// collatz_slow
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 * @using the slow solver
 */

int collatz_slow (int i, int j);

// ------------
// collatz_fast
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 * @using the cache method
 */

int collatz_fast (int i, int j);

// ---------------
// collatz_compute 
// ---------------

/**
 * @param val the number whose length is to be computed
 * @with the help of the cache
 * @return the cycle length of val 
 */

int collatz_compute (int val);

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
    // Initialize all entries in the cache to -1
    cache.resize(CACHESIZE, -1);
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
    // sanity checks
    assert(i > 0);
    assert(j > 0);

    // if i is greater than j, swap them
    if (i > j) {
        int temp = j;
        j = i;
        i = temp;
    }
    assert(i <= j);

    // Call the slow solver 
    //int max_length = collatz_slow(i, j);
    // Call the fast solver 
    int max_length = collatz_fast(i, j);
    
    return max_length;
}

// ------------
// collatz_slow
// ------------

int collatz_slow (int i, int j) {
    // define max length=1 in case input is 1
    int max_length = 1;
    
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
    // Sanity check
    assert(max_length >=1);
    return max_length;
}

// ------------
// collatz_fast
// ------------

int collatz_fast (int i, int j) {
    // define max length=1 in case input is 1
    int max_length = 1;
    
    // check all numbers between i and j
    while ( i <= j ) {
        int cur_length = collatz_compute(i);
        if (cur_length > max_length) {
            max_length = cur_length;
        }
        ++i;
    }
    // Sanity check
    assert(max_length >=1);
    return max_length;
}

// ---------------
// collatz_compute 
// ---------------

int collatz_compute (int val) {
    // Quick exit
    // Value of 1
    if (val == 1) {
        return 1;
    }
    // If this number is already in the cache
    else if (val < cache.size() && cache[val] != -1) {
        return cache[val];
    }

    // Use recursion to update cache 
    // and compute length
    int retval = -1;

    if (val % 2 == 0 ) {
        retval = 1 + collatz_compute(val/2);
        // Update cache if this value fits in the 
        // cache index range
        if (val < cache.size()) {
            cache[val] = retval;
        }
    }
    else {
        retval = 1 + collatz_compute(val*3 + 1);
        // Update cache if this value fits in the 
        // cache index range
        if (val < cache.size()) {
            cache[val] = retval;
        }
    }

    return retval;
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



