/******************************************************************************
  Title          : small_set.cpp
  Author         : Stewart Weiss
  Created on     : April 19, 2018
  Description    : Demonstration of how to use bit ops for set operations 
  Purpose        : 
  Usage          : 
  Build with     : g++ -c small_set.cpp
  Modifications  :

   NOTE:  This is hastily thrown together
 
******************************************************************************/


#include <iostream>
#include "small_set.h"



SmallSet::SmallSet(bitstring j)
{
    for (int i = 0; i < WORD_BIT; i++) {
        mask[i] = 1 << i;
    }
    set = j;
    size = __builtin_popcount (j); // only in GNU
}


bitstring do_union(SmallSet s, SmallSet t)
{
    return s.set | t.set;
}

bitstring intersection(SmallSet s, SmallSet t)
{
    return s.set & t.set;
}


bitstring SmallSet::complement()
{
    return  set ^ (unsigned)(-1);  // xor with 111...1
}

void SmallSet::add(int i)
{
    if ( 0 <= i && i < WORD_BIT ) {
        if (! contains(i) ) {
            set = set | mask[i];
            size++;
        }
    }
}


bool SmallSet::contains(int i)
{
    if ( 0 <= i && i < WORD_BIT ) 
        return( set & mask[i] )? true: false;
    else
        return false;
}

void SmallSet::print(std::ostream & out)
{
    out << "{ ";
    for (int i = 0; i < WORD_BIT; i++) {
        if (set & mask[i])
            out << i << " ";
    }
    out << "}\n";

}

