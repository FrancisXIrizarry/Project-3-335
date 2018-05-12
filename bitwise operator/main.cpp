/******************************************************************************
  Title          : main.cpp
  Author         : Stewart Weiss
  Created on     : April 19, 2018
  Description    : Demonstration of how to use bit ops for set operations 
  Purpose        : 
  Usage          : set_operations
  Build with     : g++ -o setops  main.cpp small_set.cpp
  Modifications  :

   NOTE:  This is hastily thrown together
 
******************************************************************************/


#include <iostream>
#include "small_set.h"

int main()
{

    SmallSet s1, s2, s3;
    bitstring temp1, temp2, temp3;
    std::cout << " REEEE " << std::endl;
    s1.add(1);
    s1.add(1);
    s2.add(5);
    for ( int i = 0; i< 32; i = i+3)
      s3.add(i);

    std::cout << "s1 = ";
    s1.print(std::cout);

    std::cout << "s2 = ";
    s2.print(std::cout);

    std::cout << "s3 = ";
    s3.print(std::cout);

    temp1 = do_union(s1, s2);
    SmallSet  newset1(temp1);
    std::cout << "union of s1 and s2 = ";
    newset1.print(std::cout);

    temp2 = do_union(s2, s3);    
    SmallSet  newset2(temp2);
    std::cout << "union of s2 and s3 = ";
    newset2.print(std::cout);

    temp3 = s3.complement();
    std::cout << "complement of s3 = ";
    SmallSet(temp3).print(std::cout);




    return 0;
}
