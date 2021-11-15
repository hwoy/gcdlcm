#include "gcdlcm.h"


NUM_T GCD(NUM_T a,NUM_T b)
{
	NUM_T max=a>b?a:b;
	NUM_T min=a<b?a:b;
	NUM_T rem=max%min;
	
	return !rem?min:GCD(min,rem);
}


NUM_T gcd(CPNUM_T begin,CPNUM_T end)
{
	NUM_T result=*begin;
	while(++begin<end)
		result=GCD(result,*begin);
	
	return result;
}


NUM_T LCM(NUM_T a,NUM_T b)
{
	return (a/GCD(a,b))*b;
}


NUM_T lcm(CPNUM_T begin,CPNUM_T end)
{
	NUM_T result=*begin;
	while(++begin<end)
		result=LCM(result,*begin);
	
	return result;
}


CPNUM_T factor(NUM_T num,PNUM_T buffer)
{
	unsigned int i=2;
	
	if(!num)
		return (*buffer=0,buffer+1);
	
	*buffer++=1;
	
	while(i*i<=num)
	{
		if(!(num%i))
		{
			*buffer++=i;
			num/=i;
			i=2;
		}
		else
		{
			++i;
		}
	}
	
	if(num>1)
	{
		*buffer++=num;
	}
	
	return buffer;
}
