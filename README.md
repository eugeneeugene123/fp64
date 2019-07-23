### fp64
copy of www.bitbucket.org/eugene_eugene_123/fp64

Emulation of floating point arithmetic which uses special 128bit format (64 bits mantissa, 32 bits exponent and 32 bits for attributes). This emulation is only 3-5 times slower (clang -O3 -m64, Sempron 145) than FPU and gives exact 80bit (extended, long double) results. NaNs and denormals are supported, as like as infinity. Todo: support output of denormals (they are supported internally right now, but will be flushed to zero if converted to double). Todo: conversion to long double if long double is supported by architecture. 2 different algorithms for division can be selected: Newton or tabled with derivative calculation. The first is slower, the second uses small (2Kbyte) lookup table. The first algorithm is used in AMD Ryzen processors (makes division 3 times faster than previous algorithms, according to Agner Fog's instruction tables).

TODO: fast but less accurate math functions 

TODO: debug, implement other math functions 

TODO: much faster fp32 version with 32 bit mantissa 

TODO: optimizations (lots of them!), reduce attributes size from 32 bits to ??? 

TODO: comparison with division based on native integer division 

TODO: debug multiplication (32 and 64 bits) 

TODO: sine table reduction may be seriously reduced in size: only approx. 200 bits are needed instead of 64 long long entries 

TODO: x mod N = (x mod 2^q)- cfloor(x/2^q), given that N = 2^q + c in sine reduction. x%17 = ((x(32/17))%32)*17/32  is even better
