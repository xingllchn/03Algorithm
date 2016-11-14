#include<stdio.h>
#include <stdint.h>
int main()
{
	int a=1;
	int *p=NULL;
	int64_t ret = (int64_t)a;
	*p=(int)ret;
	return 0;
}
