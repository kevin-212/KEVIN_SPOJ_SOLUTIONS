#include<bits/stdc++.h>
using namespace std;

void func (long long int&n)
{
	long long int temp=n;
	n=0;
	for(int i=0;i<=31;i+=2)
	{
		if(temp&1LL<<i)
		{
			n|=1LL<<i;	
		}
	}
}
int main()
{
	int t;
	long long int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		func(n);
		cout<<n<<endl;
	}
}
