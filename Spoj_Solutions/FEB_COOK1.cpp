#include<bits/stdc++.h>
using namespace std;
int main()
{
	
int t;
	cin>>t;
	int b;
	while(t--)
{
	cin>>b;
	b-=(b&1);
	b-=2;
	b/=2;
	cout<<(b*(b+1))/2<<endl;
}
	
}
