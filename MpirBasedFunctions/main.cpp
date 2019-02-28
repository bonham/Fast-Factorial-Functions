// Author & Copyright : Peter Luschny
// Created: 2010-01-15
// License: LGPL version 2.1 or (at your option)
// Creative Commons Attribution-ShareAlike 3.0

#include <iostream>
#include "test.h"

//  static void msg() {                                  std::cout << std::endl <<
//  "The fastes function is ParallelPrimeSwing. The computing    " << std::endl <<
//  "times of Schoenhage and PrimeSwing are approximately equal. " << std::endl <<
//  "Note that PrimeSwing uses 1/3 less space than Schoenhage's  " << std::endl <<
//  "algorithm. The space requirements in our implementation are " << std::endl <<
//  "2.PrimePi(n) for PrimeSwing and 3.PrimePi(n) for Schoenhage." << std::endl <<
//  "Writing an implementation for large n! without also paying  " << std::endl <<
//  "attention to the required space is pointless."                << std::endl;
//  std::cin.get(); }

static void FactTest()
{
    Test::FactorialSanityCheck(1000);

    ulong n = 387420489;
    Test::FactorialBenchmark(n);

}

int main()
{
   char yes; 

   std::cout << std::endl << "Factorial Test? (y/n)" << std::endl;
   std::cin >> yes; if(yes == 'y' || yes == 'Y') FactTest();

    std::cout << std::endl << "Done." << std::endl;  std::cin.get();
    return 0;
}
