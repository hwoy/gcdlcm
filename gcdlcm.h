
#ifndef __GCDLCM_H__
#define __GCDLCM_H__

typedef unsigned int NUM_T;
typedef NUM_T* PNUM_T;
typedef const NUM_T* CPNUM_T;

NUM_T GCD(NUM_T a,NUM_T b);


NUM_T gcd(CPNUM_T begin,CPNUM_T end);

NUM_T LCM(NUM_T a,NUM_T b);

NUM_T lcm(CPNUM_T begin,CPNUM_T end);

CPNUM_T factor(NUM_T num,PNUM_T buffer);

#endif

