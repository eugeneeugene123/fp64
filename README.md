### fp64
copy of www.bitbucket.org/eugene_eugene_123/fp64

Emulation of floating point arithmetic (using integer instructions) with special non-IEEE 128bit format (64 bits mantissa, 32 bits exponent and 32 bits for attributes). This emulation is only 1-5 times slower (clang -O3 -m64, Sempron 145) than FPU and gives exact 80bit (extended, long double) results. NaNs and denormals are supported, as like as infinity. 2 different algorithms for division can be selected: Newton or tabled with derivative calculation. The first is slower, the second uses small (2Kbyte) lookup table. The first algorithm is used in AMD Ryzen processors (makes division 3 times faster than previous algorithms, according to Agner Fog's instruction tables).

#### CURRENTLY IMPLEMENTED
- basic arithmetic operations (+, -, *, /, +=, -=, *=, /=, unary -)
- comparison operators (with fp64 and double numbers) (<, <=, >, >=, ==, !=)
- ifstream and ofstream operators (<<, >>)
- conversion to and from int, unsigned, long, long long, unsigned long long, float, double
- mathematical functions: sinr(sine for x in range -PI/2 < x < PI/2), sin(x), cos(x), log(x), trunc(), floor(), ceil(), round(). Last 3 functions need to be debugged right now 

#### USAGE:

#include "fp64.h"
#include <iostream>

int main(){

  fp64 x;
  fp64 y;
  std::cout.precision(18);
  std::cout << "Input x:";
  std::cin >> x;
  std::cout << "Input y:";
  std::cin >> y;
  std::cout << "x/y:" << x/y << std::endl;
  std::cout << "log(x):" << log(x) << std::endl;
  
}
  

#### TODO:
- debug operator +
- fast but less accurate math functions
- support output of denormals (they are supported internally right now, but will be flushed to zero if converted to double).
- conversion to long double if long double is supported by architecture.
- debug, implement other math functions 
- much faster fp32 version with 32 bit mantissa 
- optimizations (lots of them!), reduce attributes size from 32 bits to ??? 
- comparison with division based on native integer division 
- debug multiplication (32 and 64 bits) 
- sine table reduction may be seriously reduced in size: only approx. 200 bits are needed instead of 64 long long entries 
- x mod N = (x mod 2^q)- cfloor(x/2^q), given that N = 2^q + c in sine reduction. x%17 = ((x(32/17))%32)*17/32  is even better
