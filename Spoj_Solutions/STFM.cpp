#include<bits/stdc++.h>
using namespace std;
long long int m;
long long int fact(long long int num)
{
	
	long long int ans=1LL;
	if(num>=m)
	return 0;
	for(long long int i=2;i<=num;i++)
	{
		if(ans==0)
		break;
		ans=(ans*i)%m;
	}
	return ans;
}
int main()
{
	long long int n,temp,i,j;
	long long int p[100000],x;
	scanf("%lld %lld",&n,&m);
	
	for(i=0;i<n;i++)
	scanf("%lld",&p[i]);
	long long int ans=0,k;
	for(i=0;i<n;i++)
	{
		x=p[i];
		j=fact(x+1);
		if(x&1)
		k=((((x+1)/2)%m)*(x%m)*(x%m))%m;
		else
		k=(((x/2)%m)*(x%m)*((x+1)%m))%m;
		ans=(ans+k+j-1)%m;
		if(ans<0)
		ans+=m;	
	}
	
	printf("%lld\n",ans);
}
