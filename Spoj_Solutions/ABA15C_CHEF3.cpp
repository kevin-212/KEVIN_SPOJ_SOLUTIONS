#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int main()
{
	
	int t,n,l,h;
	cin>>t;
	int i,j,k,m;
	memset(dp,0,sizeof dp);
	
	for(i=1;i<501;i++)
	{
		dp[i][1]=1;
	}
	for(i=1;i<=500;i++)
	{
		for(j=2;j<=i;j++)
			{
			
			for(k=1;k<i;k++)
					{
						dp[i][j]+=dp[i-k][j-1];
					}
			
			}
	}
	
int ans;
	while(t--)
	{
		ans=0;
		cin>>n>>l>>h;
		for(i=l;i<=h;i++)
		ans+=dp[n][i];
		
		cout<<ans<<endl;;
		
	}
}
