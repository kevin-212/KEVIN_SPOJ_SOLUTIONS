#include<bits/stdc++.h>
using namespace std;
unsigned long long int lowbit(unsigned long long int n)
{
	return ((n^(n-1))&n);
}
unsigned long long  int num(unsigned long long int n)
{
	int i;
	for(i=63;i>=0;i--)
	{
		if(n&1ULL<<i)
		break;
	}
	return 1ULL<<i;
}
bool func(unsigned long long int  n)
{
	unsigned long long int next;
	if(n==1)
	return false;
	if(n&n-1)
	next=n-num(n);
	else
	next=n>>1;
	return !func(next);
}
int main()
{
	int t,count;
	unsigned long long int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(!func(n))
		printf("Richard\n");
		else
		printf("Louise\n");
		
	}
}
