#include<bits/stdc++.h>
using namespace std;
long long int arr[100001];
long long int dp[100003][2];
int n;


int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof dp);
		cin>>n;
		for(i=2;i<=n+1;i++)
		cin>>arr[i];	
		
		for(i=2;i<=n+1;i++)
		{
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=dp[i-1][0]+arr[i];
		}
		cout<<max(dp[n+1][0],dp[n+1][1])<<endl;
	}
	
}
