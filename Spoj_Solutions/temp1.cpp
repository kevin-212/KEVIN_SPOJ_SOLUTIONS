#include<bits/stdc++.h>
using namespace std;

const int MOD=1000000007;
int powee(int a,int b)
{
	
	int ans=1;
	while(b)
	{
		if(b&1)
		ans=(1LL*ans*a)%MOD;
		a=(1LL*a*a)%MOD;
		b>>=1;

	}
	return ans;
}

int main()
{
	int i;
	while(true)
	{
		cin>>i;
		cout<<powee(i,MOD-2)<<endl;
		
	}
}
