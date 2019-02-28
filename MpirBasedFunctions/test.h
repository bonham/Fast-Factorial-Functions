// Author & Copyright : Peter Luschny
// Created: 2010-01-15
// License: LGPL version 2.1 or (at your option)
// Creative Commons Attribution-ShareAlike 3.0

#ifndef TEST_H_
#define TEST_H_

#include <iostream>
#include "lmp.h"
#include "stopwatch.h"
#include "xmath.h"
#include "primeswing.h"
#include "schoenhage.h"
#include "binomial.h"
#include "mpir.h"
#include <math.h>

class Test {
public:

    static void FactorialBenchmark()
    {
        Xint paraswing, divisor;
        long xright, xleft, length, resultdigits, n;

        std::cout << "ParalSwing: ";
        {
	    // Input 1
	    n = 387420489;
            xleft  = 97550925;
            xright = 97550930;

	    // Input 2
	    //n = 387420489;
            //xleft  = 121200556;
            //xright = 121200562;

	    //n = 10;
            //xright = 5;
            //xleft = 3;

            length = xright - xleft + 1 ;

	    std::cout <<  "n        =  " << n << std::endl;
	    std::cout <<  "Left     =  " << xleft << std::endl;
	    std::cout <<  "Right    =  " << xright << std::endl;
	    std::cout <<  "Length   =  " << length << std::endl;

	    // factorial
            std::cout << "Start factorial calculation" << std::endl;
            lmp::Init(paraswing); StopWatch::Start();
            PrimeSwing::ParallelFactorial(paraswing, n);
            StopWatch::ElapsedTime(); std::cout << std::endl;

            // get wanted digits

            // divide by 10 ^ (xleft - 1)
            std::cout << "Prepare divide " << std::endl;
            lmp::Init(divisor);
            mpz_ui_pow_ui(divisor, 10, xleft);
            std::cout << "Divide " << std::endl;
            mpz_fdiv_q(paraswing, paraswing, divisor);

            // modulo
            std::cout << "Modulo " << std::endl;
            resultdigits = mpz_fdiv_r_ui(paraswing, paraswing, pow(10, length));
            
            // output
            //mpz_out_str(stdout, 10, paraswing);
            std::cout << "Result " << resultdigits << std::endl <<std::endl;

            lmp::Clear(paraswing);
        }
    }

};

#endif // TEST_H_
