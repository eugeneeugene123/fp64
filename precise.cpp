#include <iostream>

// todo: perl script to generate lookup table directly instead of macros
// done

#include "reciprocal_table.h"
#include "log_table.h"



unsigned cls(unsigned x){
    // count leading sign bits:
    return __builtin_clz(x)|__builtin_clz(-x);
}

long long clsll(long long x){
    // count leading sign bits:
    return __builtin_clzll(x)|__builtin_clzll(-x);
}

long long cloll(long long x){
    // count leading ones:
    return __builtin_clzll(~x);
}

long long mullhi(long long a, long long b){
    // 64bit
#if defined(__x86_64__) || defined(__aarch64__)
    __int128 ab = a;
    __int128 bb = b;
    return (long long) ((ab*bb >> 64)<<1);
#else
    // 32bit
    long long am = (a >> 63);
    long long bm = (b >> 63);
    unsigned long long au = (a^am)-am;
    unsigned long long bu = (b^bm)-bm;
    long long rm = (am^bm);
    au <<= 1;
    bu <<= 1;
    unsigned long long alo = (au&0xffffffff);
    unsigned long long ahi = (au>>32);
    unsigned long long blo = (bu&0xffffffff);
    unsigned long long bhi = (bu>>32);
    unsigned long long ur = ((ahi*bhi>>1) + (alo*bhi>>33)+(blo*ahi>>33));
    unsigned long long r = (ur^rm)-rm;
    long long sr = r;
    return sr;
#endif
}


unsigned long long umullhi(unsigned long long a, unsigned long long b){
#if defined(__x86_64__) || defined(__aarch64__)
    // 64bit
    unsigned __int128 ab = a;
    unsigned __int128 bb = b;
    return (unsigned long long) (ab*bb >> 64);
#else
    // 32bit
    unsigned long long alo = (a&0xffffffff);
    unsigned long long ahi = (a>>32);
    unsigned long long blo = (b&0xffffffff);
    unsigned long long bhi = (b>>32);
    return ahi*bhi + ((alo*bhi>>32)+(blo*ahi>>32));
#endif
}

unsigned long long umullhi2(unsigned long long a, unsigned long long b){
#if defined(__x86_64__) || defined(__aarch64__)
    // 64 bit
    unsigned __int128 ab = a;
    unsigned __int128 bb = b;
    return (unsigned long long) ((ab*bb >> 64) << 1);
#else
    // 32 bit
    unsigned long long alo = (a&0xffffffff);
    unsigned long long ahi = (a>>32);
    unsigned long long blo = (b&0xffffffff);
    unsigned long long bhi = (b>>32);
    return ((ahi*bhi + ((alo*bhi>>32)+(blo*ahi>>32)))<<1);
#endif
}

long mulhi(long a, long b){
    long long all = a;
    long long bll = b;
    return ((all*bll)>>32);
}

long smulhi(unsigned a, long b){
    long long all = a;
    long long bll = b;
    return ((all*bll)>>32);
}

unsigned umulhi2(unsigned a, unsigned b){
    unsigned long long all = a;
    unsigned long long bll = b;
    // faster version of ((all*bll)>>31)
    return (((all*bll)>>32) << 1);
}

unsigned umulhi(unsigned a, unsigned b){
    unsigned long long all = a;
    unsigned long long bll = b;
    return ((all*bll)>>32);
}

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;


typedef union {
  double d;
  struct {
    unsigned long long mantisa : 52;
    unsigned long long exponent : 11;
    unsigned long long sign : 1;
  } parts;
} double_cast;



class fp64{
public:
    fp64(float x);
    fp64(double x);
    fp64(int x);
    fp64(unsigned long x);
    fp64(unsigned x);
    fp64(long x);
    fp64(long long x);
    fp64(unsigned long long x);
    fp64(long long mant, long exp);
    fp64(long long mant, long exp, long isnan);
    fp64();
    operator int();
    operator unsigned();
    operator unsigned long();
    operator unsigned long long();
    operator long();
    operator long long();
    operator float();
    operator double();
    friend fp64 operator - (const fp64 &a);
    friend fp64 operator + (const fp64 &a, const fp64 &b);
    friend fp64 operator - (const fp64 &a, const fp64 &b);
    friend fp64 operator * (const fp64 &a, const fp64 &b);
    friend fp64 operator / (const fp64 &a, const fp64 &b);
    friend fp64 operator + (const double &a, const fp64 &b);
    friend fp64 operator - (const double &a, const fp64 &b);
    friend fp64 operator * (const double &a, const fp64 &b);
    friend fp64 operator / (const double &a, const fp64 &b);
    friend fp64 operator + (const fp64 &a, const double &b);
    friend fp64 operator - (const fp64 &a, const double &b);
    friend fp64 operator * (const fp64 &a, const double &b);
    friend fp64 operator / (const fp64 &a, const double &b);
    fp64& operator += (const fp64 &a);
    fp64& operator -= (const fp64 &a);
    fp64& operator *= (const fp64 &a);
    fp64& operator /= (const fp64 &a);
    fp64& operator += (const double &a);
    fp64& operator -= (const double &a);
    fp64& operator *= (const double &a);
    fp64& operator /= (const double &a);
    fp64 re(void);
    fp64 reT(void);               // tabled (faster) version of "re"
    fp64& operator = (const fp64 &a);
    friend bool operator < (const fp64 &a, const fp64 &b);
    friend bool operator > (const fp64 &a, const fp64 &b);
    friend bool operator == (const fp64 &a, const fp64 &b);
    friend bool operator != (const fp64 &a, const fp64 &b);
    friend bool operator < (const fp64 &a, double &b);
    friend bool operator > (const fp64 &a, double &b);
    friend bool operator == (const fp64 &a, double &b);
    friend bool operator != (const fp64 &a, double &b);
    friend bool operator < (const double &a, const fp64 &b);
    friend bool operator > (const double &a, const fp64 &b);
    friend bool operator == (const double &a, const fp64 &b);
    friend bool operator != (const double &a, const fp64 &b);
    friend std::ostream& operator << (std::ostream &os, const fp64 &a);
    friend std::istream& operator >> (std::istream &is, fp64 &a);
// up to 64 bits precision:
    friend fp64 sin(const fp64 &a);      // sine
    friend fp64 sinr(const fp64 &a);     // the same as sin, but argument must lie in range -PI/2 < x < PI/2
    friend fp64 cos(const fp64 &a);      // cosine
    friend fp64 log(const fp64 &a);      // natural logarithm
    friend fp64 normalize(unsigned long long of, unsigned long long man, unsigned exp, unsigned isnan);
    friend fp64 floor(const fp64 &a);
    friend fp64 ceil(const fp64 &a);
    friend fp64 round(const fp64 &a);
    friend fp64 trunc(const fp64 &a);
    friend fp64 __floor_neg(const fp64 &a);
    friend fp64 __ceil_pos(const fp64 &a);
    friend fp64 __roundpos(const fp64 &a);
    friend fp64 __roundneg(const fp64 &a);
    long long man;
    long exp;
    long isnan; // -1 if is NaN
private:
    static const unsigned sixteen_seventeen = 4042322161U;
    static const unsigned eight_seventeen = (2021161080>>16);
    void init(long long mant, long exp, long isnan);
};

fp64 normalize(unsigned long long of, unsigned long long man, unsigned exp, unsigned isnan){
    fp64 result;
    result.man = man;
    result.exp = exp;
    result.isnan = isnan;
    if (of){
        result.man >>= 1;
        result.man ^= (1ULL<<63);
        result.exp += 1;
        return result;
    } else {
        unsigned shift_amount = clsll(result.man)-1;
        result.man <<= shift_amount;
        result.exp -= shift_amount;
        return result;
    }
}


void fp64::init(long long mman, long eexp, long iisnan){
    unsigned sign_bits = (clsll(mman)&63);
    long long sign = (mman & (1ULL<<63));
    man = (mman << (sign_bits));
    man = (((unsigned long long)man)>>1);
    man |= sign;
    exp = eexp - (sign_bits-1);
    exp = (man == 0) ? -(1<<30):exp;
    isnan = iisnan;
}

fp64::fp64(long long mman, long eexp, long iisnan){
    init(mman, eexp, iisnan);
}

fp64::fp64(long long mman, long eexp){
    init(mman, eexp, 0);
}

fp64::fp64(long long mman){
    init(mman, 0, 0);
}

fp64::fp64(int mman){
    unsigned sign_bits = (cls(mman)&31);
    long long mmanll = (long long) mman;
    mmanll <<= (sign_bits+31);
    man = mmanll;
    exp = -sign_bits-31;
    exp = (man==0) ? (-1<<30):exp;
    isnan = 0;
}

fp64::fp64(unsigned long mman){
    init(mman, 0, 0);
}

fp64::fp64(){
    init(0,0,0);
}

fp64::fp64(unsigned long long x){
    init((x>>1),1,0);
}

fp64::fp64(unsigned mman){
    unsigned sign_bits = (cls(mman)&31);
    long long mmanll = (long long) mman;
    mmanll <<= (sign_bits+31);
    exp = -sign_bits-31;
    man = mmanll;
    exp = (man==0) ? (-1<<30):exp;
    isnan = 0;
}

fp64::fp64(float value){
    float_cast f;
    f.f = value;
    long long nm = f.parts.mantisa + (1ULL << 23);
    nm = f.parts.sign ? -nm:nm;
    if (f.parts.exponent != 255){
        init(nm, ((int)f.parts.exponent-127-23), 0);
    } else {
        init(nm, f.parts.exponent, -1);
    }
}

fp64::fp64(double value){
    double_cast d;
    d.d = value;
    long long nm = d.parts.mantisa + (1ULL<<52);
    nm = d.parts.sign ? -nm:nm;
    if (d.parts.exponent != 2047){
        init(nm, ((int)d.parts.exponent-1023-52), 0);
    } else {
        init(nm, ((int)d.parts.exponent-1023-52), -1);
    }
}

fp64::fp64(long x){
    init(x, 0, 0);
}

fp64::operator unsigned(){
    return (unsigned) operator long long();
}

fp64::operator unsigned long(){
    return (unsigned long) operator long long();
}

fp64::operator unsigned long long(){
    return (unsigned long long) operator long long();
}


fp64::operator long long(){
    unsigned long long iszero = ((63LL-(long long)exp)>>63)|(((long long)exp+63LL)>>63)|isnan|(((long long)isnan)<<32);
    long long mask = (long long) (exp >> 31);
    long long to_return = ((~iszero) & (((man << exp)& (~mask)) | ((man >> -exp) & (mask))));
    return to_return - (to_return >> 63);                                                          // negative values handling
}

fp64::operator long(){
    return (long) operator long long();
}

fp64::operator int(){
    return (int) operator long long();
}

fp64::operator float(){
    float_cast f;
    if (isnan) {
        f.parts.exponent = 255;
        f.parts.mantisa = 1;
        return f.f;
    }
    if (man == 0){
        return 0.0f;
    }
    // calculate absolute value:
    long long mask = (man >> 63);
    unsigned long long absval = (man ^ mask) - mask;
    f.parts.sign = (mask&1);
    f.parts.mantisa = ((absval >> 39) & ((1<<23)-1));
    long nexp = (exp+62+127);
    if (nexp > 255){
        // positive and negative infinity (sign is already set)
        f.parts.mantisa = 0;
        f.parts.exponent = 255;
        return f.f;
    }
    if (nexp < 0){
        f.parts.mantisa = 0;
        f.parts.exponent = 0;
        // denormals are flushed to zero
        // todo: normal denormal handling
    }
    f.parts.exponent = nexp;
    return f.f;
}

fp64::operator double(){
    double_cast d;
    if (isnan) {
        d.parts.exponent = 2047;
        d.parts.mantisa = 1;
        return d.d;
    }
    if (man == 0){
        return 0.0;
    }
    // calculate absolute value:
    long long mask = (man >> 63);
    unsigned long long absval = (man ^ mask) - mask;
    d.parts.sign = (mask&1);
    d.parts.mantisa = ((absval >> 10) & ((1ULL<<52)-1));
    long nexp = (exp+62+1023);
    if (nexp > 2047){
        // positive and negative infinity (sign is already set)
        d.parts.mantisa = 0;
        d.parts.exponent = 1023;
        return d.d;
    }
    if (nexp < 0){
        d.parts.mantisa = 0;
        d.parts.exponent = 0;
        // denormals are flushed to zero
        // todo: normal denormal handling
    }
    d.parts.exponent = nexp;
    return d.d;
}

fp64 operator -(const fp64 &a){
    fp64 result;
    result.man = -a.man;
    result.exp = a.exp;
    result.isnan = a.isnan;
    return result;
}

fp64 operator + (const fp64 &a, const fp64 &b){
    //long long maxa = (long long)(b.exp - a.exp);
    //maxa >>= 63;
    //long imaxa = (long) maxa;
    long long bm,lm;
    long long be,le;
    fp64 result;
    // todo: sometimes it is better to use commented variant. when?
    //bm = (a.man&maxa) | (b.man&(~maxa));
    //lm = (b.man&maxa) | (a.man&(~maxa));
    //be = (a.exp&imaxa) | (b.exp&(~imaxa));
    //le = (b.exp&imaxa) | (a.exp&(~imaxa));
    bm = (a.exp > b.exp) ? a.man:b.man;
    lm = (a.exp > b.exp) ? b.man:a.man;
    be = (a.exp > b.exp) ? a.exp:b.exp;
    le = (a.exp > b.exp) ? b.exp:a.exp;

    int diffexp = be-le;
    long long ignoremin = (long long) ((diffexp-63) >> 31);
    long long of = __builtin_saddll_overflow(bm, (ignoremin & (lm >> diffexp)), &(result.man));
    return normalize(of, result.man, be, (a.isnan|b.isnan));
    // todo: check >>1 | 1 when overflow happens (optimization)
    //long long overman = (bm >> 1) + ((ignoremin & (lm >> diffexp))>>1);
    // todo: optimize this!!!
    //return fp64( ((result.man&(of-1))|(overman&(-of))), be+of, (a.isnan|b.isnan) );
}

fp64 operator - (const fp64 &b, const fp64 &a){
    fp64 c(-a.man, a.exp, a.isnan);
    return c+b;
}

fp64 operator * (const fp64 &a, const fp64 &b){
    fp64 result;
    result.man = mullhi(b.man, a.man);
    unsigned of = (cls(result.man >> 32)&2);
    result.man = of ? (result.man << 1):result.man;
    result.exp = of ? (b.exp - 1):b.exp;
    result.exp += a.exp+63;
    result.isnan = a.isnan | b.isnan;
    return result;
}

fp64& fp64::operator = (const fp64 &a){
    man = a.man;
    exp = a.exp;
    isnan = a.isnan;
    return *this;
}

fp64& fp64::operator += (const fp64 &a){
    *this = *this+a;
    return *this;
}

fp64& fp64::operator -= (const fp64 &a){
    *this = *this-a;
    return *this;
}

fp64& fp64::operator *= (const fp64 &a){
    *this = *this*a;
    return *this;
}


fp64 fp64::re(){
    // returns reciprocal:
    // Newton-Raphson
    // todo: other method (deriv) is faster
    if (man == 0) return fp64(0, 0, -1);
    unsigned long long D = ((man>>63)^man) - (man>>63);
    unsigned Du = (D >> 31);
    unsigned long long sign = (man >> 63);
    unsigned mult = (((D & (~(1ULL << 62)))>>46)*eight_seventeen);
    unsigned x0 = (sixteen_seventeen - mult);

    x0 += smulhi(x0, -umulhi2(Du, x0));
    x0 += smulhi(x0, -umulhi2(Du, x0));
    x0 += smulhi(x0, -umulhi2(Du, x0));

    unsigned long long x0ll = (((unsigned long long)x0)<<31) + (mullhi((((unsigned long long)x0)<<31), -umullhi2((D<<1), (((unsigned long long)x0)<<32)))>>1);
    // todo: optimize this!!!
    //return fp64(((x0ll ^ sign) - sign), -exp-125, 0);
    // done:
    fp64 result;
    result.man = (x0ll^sign)-sign;
    result.exp = -exp-125;
    result.isnan = isnan;
    return result;
}

fp64 fp64::reT(){
    // returns reciprocal:
    // 1/x = (1/x0)*(1-y+y^2-y^3+y^4-y^5+y^6-y^7)
    // y = deltax/x0
    // debug: 1.22801 and 1.22802. what is the difference?
    if (man == 0) return fp64(0,0,-1);
    unsigned long long sign = (man>>63);
    unsigned long long D = ((man>>63)^man) - (man>>63);
    unsigned Du = (D>>54);          // 31+24
    unsigned long long x0 = (((unsigned long long)Du) << 55);
    unsigned long long re0 = __reciprocal_div_table[(Du&255)];
    unsigned long long deltax = (D<<1)-x0;
    unsigned long long y = ((umullhi(deltax, re0))<<1);
    unsigned long long omy = -y;
    unsigned long long yy = (umullhi(y,y));
    unsigned long long yyyy = umullhi(yy,yy);
    unsigned long long quatro = omy+(umullhi(yy,omy)<<0);
    unsigned long long dentro = quatro+((umullhi(yyyy,quatro)));
    unsigned long long rex = (y==0) ? (re0>>1) : (umullhi(re0,dentro)>>1)+1;
    fp64 result;
    result.man = (rex^sign)-sign;
    result.exp = -exp-125;
    result.isnan = isnan;
    return result;
}



fp64 operator / (const fp64 &a, const fp64 &b){
    fp64 c = b;
    return a*(c.reT());
}

fp64& fp64::operator /= (const fp64 &a){
    fp64 c = a;
    *this = *this*c.re();
    return *this;
}

bool operator < (const fp64 &a, const fp64 &b){
    // todo: optimize this!!!
    //fp64 c = a-b;
    //return (c.man < 0)&&(!c.isnan);
    // done: (optimize better!)
    if ((a.man ^ b.man) < 0) return (a.man < b.man)&&(!a.isnan)&&(!b.isnan);
    if (a.exp != b.exp) return (((a.man>0)&&(a.exp<b.exp))||((a.man<=0)&&(a.exp>b.exp)))&&(!a.isnan)&&(!b.isnan);
    // same signs, same exponents:
    return (a.man < b.man)&&(!a.isnan)&&(!b.isnan);

}

bool operator > (const fp64 &a, const fp64 &b){
    return (b < a);
}

bool operator == (const fp64 &a, const fp64 &b){
    return ((a.man==b.man)&&((a.exp==b.exp)||(a.man==0)))&&(!a.isnan)&&(!b.isnan);
}

bool operator != (const fp64 &a, const fp64 &b){
    return !(a==b);
}

bool operator < (const fp64 &a, const double &b){
    // todo: optimize this!
    return (a<(fp64)b);
}

bool operator > (const fp64 &a, const double &b){
    // todo: optimize this!
    return (a>(fp64)b);
}

bool operator == (const fp64 &a, const double &b){
    // todo: optimize this!
    return (a == (fp64)b);
}

bool operator != (const fp64 &a, const double &b){
    // todo: optimize this!
    return (a != (fp64)b);
}

bool operator < (const double &a, const fp64 &b){
    // todo: optimize this!
    return ((fp64)a<b);
}

bool operator > (const double &a, const fp64 &b){
    // todo: optimize this!
    return ((fp64)a>b);
}

bool operator == (const double &a, const fp64 &b){
    // todo: optimize this!
    return ((fp64)a == b);
}

bool operator != (const double &a, const fp64 &b){
    // todo: optimize this!
    return ((fp64)a != b);
}

fp64 operator + (const double &a, const fp64 &b){
    // todo: optimize this!
    return (fp64)a+b;
}

fp64 operator - (const double &a, const fp64 &b){
    // todo: optimize this!
    return (fp64)a-b;
}

fp64 operator * (const double &a, const fp64 &b){
    // todo: optimize this!
    return (fp64)a*b;
}

fp64 operator / (const double &a, const fp64 &b){
    // todo: optimize this!
    return (fp64)a/b;
}

fp64 operator + (const fp64 &a, const double &b){
    // todo: optimize this!
    return a+(fp64)b;
}

fp64 operator - (const fp64 &a, const double &b){
    // todo: optimize this!
    return a-(fp64)b;
}

fp64 operator * (const fp64 &a, const double &b){
    // todo: optimize this!
    return a*(fp64)b;
}

fp64 operator / (const fp64 &a, const double &b){
    // todo: optimize this!
    return a/(fp64)b;
}

fp64& fp64::operator += (const double &a){
    // todo: optimize this!
    *this += (fp64)a;
    return *this;
}

fp64& fp64::operator -= (const double &a){
    // todo: optimize this!
    *this -= (fp64)a;
    return *this;
}

fp64& fp64::operator *= (const double &a){
    // todo: optimize this!
    *this *= (fp64)a;
    return *this;
}

fp64& fp64::operator /= (const double &a){
    // todo: optimize this!
    *this /= (fp64)a;
    return *this;
}

fp64 trunc(const fp64 &a){
    // chop fractional part:
    fp64 result;
    result.isnan = a.isnan;
    if (a.exp > 0){
        // infinity?
        return a;
    } else {
        // todo: optimize it!!!
        long long sign = (a.man >> 63);
        result.man = (a.man^sign)-sign;
        unsigned long long resultman = result.man;
        resultman >>= (-a.exp);
        resultman <<= (-a.exp);
        result.man = resultman;
        result.exp = a.exp;
        result.man = (result.man^sign)-sign;
    }
    return result;
}

fp64 round(const fp64 &a){
    // round to the nearest value:
   if (a.exp >= 0){
        fp64 b;
        b = a;
        b.isnan = -1;
        return b;
   } else {
        if (a.man > 0) return __roundpos(a);
        else return __roundneg(a);
   }
}

fp64 __roundpos(const fp64 &a){
    fp64 result;
    result.isnan = a.isnan;
    result.man = a.man;
    result.exp = a.exp;
    result.man >>= (-result.exp + 1);
    result.man += 1;
    result.man >>= 1;
    result.man <<= (-result.exp);
    if (result.man & (1ULL << 63)){
        // overflow
        result.man >>= 1;
        result.exp += 1;
    }
    return result;
}

fp64 __roundneg(const fp64 &a){
    fp64 result;
    result.isnan = a.isnan;
    result.man = a.man;
    result.exp = a.exp;
    result.man >>= (-result.exp + 1);
    result.man -= 1;
    result.man >>= 1;
    result.man <<= (-result.exp);
    if (result.man & (1ULL << 63)){
        // overflow
        result.man >>= 1;
        result.exp += 1;
    }
    return result;
}


fp64 floor(const fp64 &a){
    // calculate floor of the value (round down to the nearest integer)
    if (a.man >= 0) return trunc(a);
    else return __floor_neg(a);
}

fp64 ceil(const fp64 &a){
    // calculate ceil of the value (round up to the nearest integer)
    if (a.man < 0) return trunc(a);
    else return __ceil_pos(a);
}

fp64 __floor_neg(const fp64 &a){
    if (a.exp > 0){
        // infinity?
        fp64 result;
        result.man = a.man;
        result.exp = a.exp;
        result.isnan = -1;
    } else if (a.exp == 0){
        fp64 result;
        result.man = a.man;
        result.exp = a.exp;
        result.isnan = a.isnan;
    } else {
        fp64 result;
        result.isnan = a.isnan;
        result.man = a.man;
        result.man >>= (-a.exp);
        result.man -= 1;
        unsigned signs = cloll(result.man);
        result.man <<= (signs-1);
        result.exp = -(signs-1);
        return result;
    }
}

fp64 __ceil_pos(const fp64 &a){
    if (a.exp > 0){
        // infinity?
        fp64 result;
        result.man = a.man;
        result.exp = a.exp;
        result.isnan = -1;
    } else if (a.exp == 0){
        fp64 result;
        result.man = a.man;
        result.exp = a.exp;
        result.isnan = a.isnan;
    } else {
        fp64 result;
        result.isnan = a.isnan;
        result.man = a.man;
        result.man >>= (-a.exp);
        result.man += 1;
        unsigned signs = __builtin_clzll(result.man);
        result.man <<= (signs-1);
        result.exp = -(signs-1);
        return result;
    }
}



// math functions:
fp64 sinr(const fp64 &a){
// algorithm for calculating sine function (60-61 bits of precision are guaranteed)
// sin(x) = x+
// -1.666666666666666455027514024765045391390e-1* x^3 +
// 8.333333333333114005518116351849428382702e-3* x^5 +
// -1.984126984118596130918508421649618709748e-4* x^7 +
// 2.755731920778698167648701758421693093376e-6* x^9 +
// -2.505210660664064422936006224669604274226e-8* x^11 +
// 1.605892783658265569622248292940125516955e-10* x^13 +
// -7.642712930271124715062339043717404392317e-13* x^15 +
// 2.718496391757936169840814495224274873348e-15* x^17

// = x(1-x^2(...-...x^2-...x^4+...x^6-...+...-...+...x^14))
// = ..

// xx represents part of 4 (max val of x = pi/2 < 2)
// so a0 = ..*2^66 (unsigned part of 0.25)
// a1 = ..*2^68
// a2 = ..*2^70
// ..
    const unsigned long long a0 = 12297829382473032849ULL;
    const unsigned long long a1 = 2459565876494542147ULL;
    const unsigned long long a2 = 234244369188972280ULL;
    const unsigned long long a3 = 13013576058459312ULL;
    const unsigned long long a4 = 473220914257907ULL;
    const unsigned long long a5 = 12133782810608ULL;
    const unsigned long long a6 = 230986824832ULL;
    const unsigned long long a7 = 3286460478ULL;

    // step 0: get sign of x
    unsigned long long sign = (a.man >> 63);
    unsigned long long absman = (a.man^sign)-sign;

    // step 1: calculate x^2
    // mullhi gives x*x*2
    const long exp_PI_2 = -62;
    // 2^64 = 4;
    unsigned long long xx = umullhi((absman<<1),(absman<<1))>>((exp_PI_2-a.exp)*2);    // 1.2 (+)
    // step 2: calculate everything
    unsigned long long p1 = a0-umullhi(a1,xx);
    unsigned long long p2 = a2-umullhi(a3,xx);
    unsigned long long p3 = a4-umullhi(a5,xx);
    unsigned long long p4 = a6-umullhi(a7,xx);
    unsigned long long xxxx = umullhi(xx,xx);
    unsigned long long q1 = umullhi(p2,xxxx)+p1;
    unsigned long long q2 = umullhi(p4,xxxx)+p3;
    unsigned long long xxxxxxxx = umullhi(xxxx,xxxx);
    unsigned long long r = umullhi(q2,xxxxxxxx)+q1;
    unsigned long long xxr = umullhi(xx,r);
    unsigned long long omxxr = -xxr;
    long long newman = mullhi(absman,(omxxr>>1));
    long newexp = a.exp;
    //if (!(newman&(1ULL<<62))) {
    //    newman <<= 1;
    //    newexp -= 1;
    //}
    unsigned shift_amount = ((newman>>62)&1)^1;
    newman <<= shift_amount;
    newexp -= shift_amount;
    fp64 result;
    result.man = newman;
    result.exp = newexp;
    result.isnan = a.isnan;
    // apply sign:
    result.man = (result.man^sign)-sign;
    // TODO: optimize sign handling!!! maybe change a little shift_amount function?
    return result;
}

fp64 sin(const fp64 &a){
    // example which explains normal range reduction algorithm:
    // 175 % 17 = ceil(((175*(32/17))&31)*(17/32))
    // so
    // (1.23 * 2^32) fmod PI = ceil (((1.23*2^32*(2^32/pi))&(2^32-1))*(pi/2^32))

    // simple range reduction algorithm:
    // x-> int128
    // (1/pi) -> int128
    // pi -> int128
    // x-(1/pi)*x*pi -> int128
    // uses 2 int128 multiplications

    // TODO: implement first algorithm
    // right now simply calculate x - long long(x*(1/(2*Pi)))*2*Pi
    // todo: optimize this algorithm (use integer arithmetic, not fp64) and put it into sini function (imprecise range reduction)

    fp64 dpi;  // pi*2
    dpi.man = 7244019458077122842ULL;
    dpi.exp = -60;
    dpi.isnan = 0;

    fp64 rdpi;   // (1/pi*2)
    rdpi.man = 5871781006564002452;
    rdpi.exp = -65;
    rdpi.isnan = 0;

    fp64 pi;   // 3.1415 ..
    pi.man = 7244019458077122842ULL;
    pi.exp = -61;
    pi.isnan = 0;

    fp64 hpi;  // pi/2
    hpi.man = 7244019458077122842ULL;
    hpi.exp = -62;
    hpi.isnan = 0;

    fp64 x = a;
    fp64 z = (long long)(x*rdpi);
    x = x - z*dpi; // now x lies in range [0;2*pi]:
    x = (x.man > 0) ? x:x+dpi;

    // now reduce x to range [0;pi]
    fp64 x1 = x-pi;
    fp64 y = x;
    y = (x1.man > 0) ? x1 : x;

    unsigned long long sign = ~(x1.man>>63);
    // now reduce y to range [0;pi/2]
    fp64 y1 = y-hpi;
    fp64 t = y;
    t = (y1.man < 0) ? y:pi-y;
    t.man = (t.man^sign)-sign;

    return sinr(t);

}

fp64 cos(const fp64 &a){
    fp64 hpi;  // pi/2
    hpi.man = 7244019458077122842ULL;
    hpi.exp = -62;
    hpi.isnan = 0;
    return sin(hpi-a);
}

fp64 log(const fp64 &a){
    // 62 bits and better precision:
    // log (1.7*2^23) = logt(179)+logp(1.000459770114942528735632183908)+23*log2
    // requires reciprocal table (reciprocal_table.h)
    const unsigned long long one_third = 3074457345618258602ULL;
    const unsigned long long one_fifth = 1844674407370955161ULL;
    const unsigned long long one_sixth = 1537228672809129301ULL;
    const unsigned long long one_seventh = 1317624576693539401ULL;

    fp64 result;
    unsigned long long man = a.man;
    // step 0 : nan for negative values
    result.isnan = (a.man >> 63);
    // step 1 : get i
    unsigned i = ((a.man >> 54)&255);
    // step 2: logt
    man = mullhi(man, (__reciprocal_div_table[i]>>1))+1;
    unsigned long long logt = __log_table[i];
    // step 3: logp (7th degree polynomial)
    unsigned long long x = ((man&(~(1ULL<<62)))<<1);
    // ln(1+x) = x - x^2/2 + x^3/3 - x^4/4 + x^5/5 - x^6/6 + x^7/7
    unsigned long long xx = mullhi(x,x);
    unsigned long long p1 = x-(xx>>1);
    unsigned long long p2 = mullhi(x, one_third)-(xx>>2);
    unsigned long long p3 = mullhi(x, one_fifth)-mullhi(xx,one_sixth);
    unsigned long long p4 = mullhi(x, one_seventh);
    unsigned long long xxxx = mullhi(xx,xx);
    unsigned long long q1 = p1+mullhi(p2,xx);
    unsigned long long q2 = p3+mullhi(p4,xx);
    unsigned long long logp = q1+mullhi(q2,xxxx);

    //result.man = logt + (logp<<(__log_exp[i]));
    long long of = __builtin_saddll_overflow(logt, (logp<<(__log_exp[i])), &(result.man));
    if (of) {
        result.man >>= 1;
        unsigned long long sign = (result.man & (1ULL << 62));
        result.man ^= (sign<<1);
    }
    result.exp = -63-__log_exp[i]+of;
    result.isnan |= a.isnan;

    // todo: optimize it
    // add a.exp * ln(2)
    // fp64 aexp = (int)a.exp+62;
    fp64 aexp;
    unsigned shift_amount = cls(a.exp+62);
    aexp.man = (((long long)a.exp+62)<<(31+shift_amount));
    aexp.exp = -31-shift_amount;
    aexp.isnan = 0;
    fp64 ln2;
    ln2.man = 6393154322601327830;
    ln2.exp = -63;
    ln2.isnan = 0;

    return result + aexp*ln2;

}


std::ostream& operator << (std::ostream &os, const fp64 &a){
    // todo: full 64 bit precision
    fp64 b = a;
    os << (double)b;
    return os;
}

std::istream& operator >> (std::istream &is, fp64 &a){
    // todo: full 64 bit precision
    double x;
    is >> x;
    a = (fp64)x;
    return is;
}

#define REAL fp64
#include <ctime>
#include <cmath>


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

    return 0;
}
