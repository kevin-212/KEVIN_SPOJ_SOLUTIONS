#include<bits/stdc++.h>
using namespace std;


int arr[1000001];
bool visited[1000001];
int dp[1000001];

int main()
{
	int n,i;
int count[10001];	
	for(i=0;i<=1000000;i++)
	visited[i]=false,dp[i]=0;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>arr[i];
dp[n]=0;
	for(i=n-1;i>=0;i--)
	{
		dp[i]=dp[i+1];
		if(!visited[arr[i]])
		dp[i]++;
	}
	int q1,x,r,l;
	count[0]=0;
	cin>>q1;
	for(i=1;i<=q1;i++)
	{
		cin>>x>>r;
		l=count[i-1]+x;
		r--,l--;
		if(l<0)
		l=0;
		count[i]=dp[l]-dp[r+1];
	}
	for(i=1;i<=q1;i++)
	cout<<count[i]<<endl;
	
}
