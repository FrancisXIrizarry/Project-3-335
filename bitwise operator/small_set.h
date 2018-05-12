/******************************************************************************
  Title          : small_set.h
  Author         : Stewart Weiss
  Created on     : April 19, 2018
  Purpose        : 
  Usage          : 
  Build with     : 
  Modifications  :

   NOTE:  This is hastily thrown together
 
******************************************************************************/
#ifndef __SMALL_SET_H__
#define __SMALL_SET_H__



#include <limits.h>
#include <iostream>

// A bitstring is an integer whose value is irrelevant to us but whose
// bits define which elements are in the set that it represents: if the ith
// bit is 1, it is in the set, and if it is 0, it is not. 
typedef  int bitstring;


/** SmallSet represents a small set, not more than the wordsize of the
 *  machine on which it is compiled.
 *  It uses bitstrings to represent sets, and bitwise operations on them
 *  with masks and bitstrings.
 */
class SmallSet
{
public:
    /** Constructor
     *  Initializes a set to contain the members represented by the positions
     *  of the 1-bits in integer j. 
     */
    SmallSet(bitstring j=0);

    /** complement() returns an integer bitstring representing the complement
     *  of the set.
     */
    bitstring   complement();

    
    void  add(int i);


    bool  contains(int i);
    void  print(std::ostream& out);
    friend bitstring   do_union(SmallSet s, SmallSet t);
    friend bitstring   intersection(SmallSet s, SmallSet t);
    

private:
    bitstring mask[WORD_BIT];
    bitstring set;
    int size;
};


#endif /* __SMALL_SET_H__ */



