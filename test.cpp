#define REAL fp64
#include <ctime>
#include <cmath>
#include <iostream>
#include "fp64.h"

int main(void){

 // PI = 4 - 4/3 + 4/5 - 4/7 ...
    REAL PI = 4.0;
    int flag = 0;
    clock_t beg = clock();
    for (unsigned i=3; i<50000000; i+= 2){
        if (flag){
            PI += (REAL)4.0/(REAL)i;
        } else {
            PI -= (REAL)4.0/(REAL)i;
        }
        flag = !flag;
    }
    clock_t fin = clock();
    std::cout.precision(18);
    std::cout << "Value of PI(fp64, my new division algorithm (deriv)):" << PI << std::endl;
    std::cout.precision(8);
    std::cout << "Calculation time:" << (double)(fin-beg)/(double)CLOCKS_PER_SEC << " seconds" << std::endl;


    PI = 4.0;
    flag = 0;
    beg = clock();
    for (unsigned i=3; i<50000000; i+= 2){
        if (flag){
            REAL r = ((REAL)i).re();
            PI += (REAL)4.0*r;
        } else {
            REAL r = ((REAL)i).re();
            PI -= (REAL)4.0*r;
        }
        flag = !flag;
    }
    fin = clock();
    std::cout.precision(18);
    std::cout << "Value of PI(fp64, my old division algorithm (Newtn)):" << PI << std::endl;
    std::cout.precision(8);
    std::cout << "Calculation time:" << (double)(fin-beg)/(double)CLOCKS_PER_SEC << " seconds" << std::endl;


    flag = 0;
    beg = clock();
    long double pi = 4.;
    for (unsigned i=3; i<50000000; i+= 2){
        if (flag){
            pi+= (long double)4.0/(long double)i;
        } else {
            pi -= (long double)4.0/(long double)i;
        }
        flag = !flag;
    }
    fin = clock();
    std::cout.precision(18);
    std::cout << "Value of PI(double):" << pi << std::endl;
    std::cout.precision(8);
    std::cout << "Calculation time:" << (double)(fin-beg)/(double)CLOCKS_PER_SEC << " seconds" << std::endl;



    std::cout.precision(18);
    beg = clock();
    REAL sum = 0;
    REAL s = 0;
    REAL mult = 0.5e-6;
    for (unsigned i=0; i<1000000; i++){
        REAL ii = i;
        REAL iim = ii*mult;
        s = sinr(iim+s);
        sum += s;
    }
    fin = clock();
    std::cout << "Value of sine sum:" << sum << std::endl;
    std::cout.precision(4);
    std::cout << "Calculation time( fp64 ):" << (double)(fin-beg)/(double)CLOCKS_PER_SEC << " seconds" << std::endl;

    std::cout.precision(18);
    beg = clock();
    double SUM = 0;
    double S = 0;
    for (unsigned i=0; i<1000000; i++){
        S = sin((double)i*(double)0.5e-6+S);
        SUM += S;
    }
    fin = clock();
    std::cout << "Value of sine sum:" << SUM << std::endl;
    std::cout.precision(4);
    std::cout << "Calculation time(double):" << (double)(fin-beg)/(double)CLOCKS_PER_SEC << " seconds" << std::endl;

    std::cout.precision(18);
    beg = clock();
    SUM = 0;
    double L = 0;
    for (unsigned i=500000; i<1000000; i++){
        L = log((double)i*(double)0.5e-6+L+1.);
        SUM += L;
    }
    fin = clock();
    std::cout << "Value of log sum:" << SUM << std::endl;
    std::cout.precision(4);
    std::cout << "Calculation time(double):" << (double)(fin-beg)/(double)CLOCKS_PER_SEC << " seconds" << std::endl;

    std::cout.precision(18);
    beg = clock();
    sum = 0;
    REAL l = 0;
    for (unsigned i=500000; i<1000000; i++){
        l = log((REAL)i*(REAL)0.5e-6+l+(REAL)1.);
        sum += l;
    }
    fin = clock();
    std::cout << "Value of log sum:" << sum << std::endl;
    //std::cout << "sum.man:" << sum.man << std::endl;
    //std::cout << "sum.exp:" << sum.exp << std::endl;
    std::cout.precision(4);
    std::cout << "Calculation time( fp64 ):" << (double)(fin-beg)/(double)CLOCKS_PER_SEC << " seconds" << std::endl;

    std::cout.precision(18);
    fp64 su = 0.0;
    /*
    while(1){
        fp64 x;
        std::cout << "Input x:";
        std::cin >> x;
        std::cout << "x:" << x << std::endl;
        su+=x;
        std::cout << "su:" << su << std::endl;
        std::cout << "log(x) ( fp64 ):" << log(x) << std::endl;
        std::cout << "log(x) (double):" << log((double)x) << std::endl;
        std::cout << "trunc(x):" << trunc(x) << std::endl;
        std::cout << "floor(x):" << floor(x) << std::endl;
        std::cout << "ceil(x):" << ceil(x) << std::endl;
        std::cout << "round(x):" << round(x) << std::endl;
    }
    */

    return 0;
}
