from SwingFactorialPy_gmpy2 import factorialPS
from gmpy2 import mpz, add, div, mul, sub, t_divmod, f_mod
from time import time
 
def cutDigits(f, left, right):

    length = left - right + 1
    return f_mod(div(f, pow(mpz(10), mpz(right))), pow(mpz(10), length))

print("")
start = time()
print("Calculating factorial of 9**9. ")
n = pow(mpz(9),9)
f = factorialPS(n)
lap1 = time()
print("Factorial complete. {:.0f}s".format(lap1-start), flush=True)

left, right = 97550930, 97550925
print("")
print("Cutting digits from position {} to {}: ".format(left, right), end='', flush=True)
print(cutDigits(f, left, right))
lap2 = time()
print("{:.1f}s".format(lap2-lap1))

left, right = 121200562 , 121200556
print("")
print("Cutting digits from position {} to {} :".format(left, right), end='', flush=True)
print(cutDigits(f, left, right))
lap3 = time()
print("{:.1f}s".format(lap3-lap2))

##### print check
#n = mpz(1000000)
#left = 4000000
#
#start = time.time()
#f = factorialPS(n) 
#lap1 = time.time()
#ftime = lap1 - start
#print("ftime={:1.3f}".format(ftime))
#digits = div(f, (10**left)) % (10 ** 6)
#dtime = time.time() - lap1
#print("n={}, ftime={:1.2f}s, dtime={:1.2f}, lastdigits={}".format(
#    n,
#    ftime,
#    dtime,
#    digits
#    ))
#        
#for exponent in range(6,10):
#
#    print("Exp: {}".format(exponent))
#    n = mpz(9**exponent)
#    left = 4000000
#
#    start = time.time()
#    f = factorialPS(n) 
#    lap1 = time.time()
#    ftime = lap1 - start
#    print("n={}, ftime={:1.2f}s".format( n, ftime,))
#        
#
