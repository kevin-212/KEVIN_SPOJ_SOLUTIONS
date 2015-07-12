#include<bits/stdc++.h>
using namespace std;

int func(int n)
{
	int i;
	for( i=30;i>=0;i--)
	{
		if((n&1<<i) !=0)
		break;
	}
	return i;
}
int main()
{
	long long int t,a,b,ans;
	int i;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;

		if(a==b)
		printf("%lld\n",a);
		else{
		ans=0;
		for(i=31;i>=0;i--)
		{
			if(b&1LL<<i)
			{
				
				if(a&1LL<<i)
				ans|=1LL<<i;
				else
				break;
			}
		}
		printf("%lld\n",ans);
		}
	}
}
