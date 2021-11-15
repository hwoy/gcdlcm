#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "gcdlcm.h"

enum 
{
	err_noargs,
	err_malloc,
	err_notnumber,
	err_zero
};

static const char *errmsg[]=
{
	"No arguments",
	"Can not allocate memory",
	"Not a number",
	"Zero is not allowed",
NULL};

static void showerr(const char **errmsg,unsigned int errn);

static void showhelp(const char *progname);

static void freeargs(void);

static void showoutput(CPNUM_T begin,CPNUM_T end);


static NUM_T *args=NULL;


int main(int argc,const char *argv[])
{
	int i;
	
	if(argc<2)
	{
		showerr(errmsg,err_noargs);
		showhelp(argv[0]);
		return 0;
	}
	
	if(!(args=(NUM_T *)malloc(sizeof(NUM_T)*(argc-1))))
	{
		showerr(errmsg,err_malloc);
		return 1;
	}
	
	atexit(freeargs);
	
	for(i=1;i<argc;++i)
	{
		if(!isUint(argv[i]))
		{
			fprintf(stderr,"args %u: %s\n",i,argv[i]);
			showerr(errmsg,err_notnumber);
			return 0;	
		}
		
		if(!(args[i-1]=s2ui(argv[i])))
		{
			fprintf(stderr,"args %u: %s\n",i,argv[i]);
			showerr(errmsg,err_zero);
			return 0;	
		}
	}
	
	showoutput(args,args+argc-1);
	
	return 0;
}

static void showerr(const char **errmsg,unsigned int errn)
{
	fprintf(stderr,"Error %u:%s\n",errn,errmsg[errn]);
}

static void showhelp(const char *progname)
{
	fprintf(stderr,"\nUSAGE: %s num1 num2 num3 ...\n",progname);
	fprintf(stderr,"num = positive integer except zero\n");
	fprintf(stderr,"\nExample\n");
	fprintf(stderr,"%s 4 10\n",progname);
	fprintf(stderr,"%s 1 2 3 4 5\n",progname);
	
}

static void freeargs(void)
{
	if(args)
		free(args);
}

static void showoutput(CPNUM_T begin,CPNUM_T end)
{
	NUM_T buffer[sizeof(NUM_T)*8+1];
	CPNUM_T start;
	
	for(start=begin;start<end;++start)
	{
		CPNUM_T buffer_start=buffer;
		CPNUM_T buffer_end=factor(*start,buffer);
		printf("%u = ",*start);
		
		for(;buffer_start<buffer_end;++buffer_start)
		{
			if(buffer_start<buffer_end-1)
				printf("%u x ",*buffer_start);
			else
				printf("%u\n",*buffer_start);
		}
	}
	
	putchar('\n');
	
	printf("[ GCD=%u , LCM=%u ]\n",gcd(begin,end),lcm(begin,end));
}
