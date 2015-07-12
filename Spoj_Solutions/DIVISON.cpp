#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INV 333333336
int main()
{
	unsigned long long int n,a,b;
	while(scanf("%llu",&n)!=EOF){
	
	if(n&1)
	{
	a=1,b=2;
	while(n)
	{
		if(n&1)
			a=(a*b)%MOD;
			b=(b*b)%MOD;
		
		n=n>>1;
	}
	printf("%llu\n",((a+1)*INV)%MOD);
		
	}
	
	else
	{
		a=1,b=2;
		while(n)
		{
			if(n&1)
			a=(a*b)%MOD;
			b=(b*b)%MOD;
			n=n>>1;
		}
		printf("%llu\n",((a+2)*INV)%MOD);
	}
}
}
