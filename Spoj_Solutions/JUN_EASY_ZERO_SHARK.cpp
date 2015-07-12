#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll fibo[100000];
void init()
{
	fibo[0] = 0;
	fibo[1] = 2;
	fibo[2] = 3;
	for(ll i = 3 ; i < 100000 ; i++)
	{
		fibo[i] = (fibo[i-1] + fibo[i-2]) % 1000000007;
	}
}

int main()
{
	int t;
	cin>>t;
	init();
	while(t--)
	{
		ll n;
		cin>>n;
		if(n==1) cout<<0<<endl;
		else if(n==2) cout<<1<<endl;
		else if(n==3) cout<<2<<endl;
		else
		{
			ll count = 0;
			for(ll i = 1; i < n ; i++)
			{
				ll a = ((i>2)?(fibo[i-2]):1);
				ll b = ((i<(n-2))?(fibo[n-i-2]):1);
				count = (count + ((a * b )%1000000007))%1000000007;
			}
			cout<<count<<endl;
		}
	}
}
