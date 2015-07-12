#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

struct cmp{
	
	bool operator()(pii a,pii b)
	{
		return a.second>b.second;
		
	}
};
int main()
{
	int n,T,t,p,q;
	scanf("%d %d",&n,&T);
	int ans=0,temp=T,temp1;
	vector<pii>kp[7];
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&t,&p,&q);
		kp[t].push_back(pii(p,q));
	}
	
	int dp[7][1001];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=T;i++)
	{
		dp[0][i]=INT_MAX;
	}
	for(int i=1;i<=6;i++)
	{
		
		int sz=kp[i].size();
			if(sz==0)
			{
				ans=0;
				break;
			}
			
		for(int k=0;k<sz;k++)
		{
			p=kp[i][k].first;
			q=kp[i][k].second;
			for(int j=p;j<=T;j++)
			{
				{
					dp[i][j]=max(dp[i][j],min(q,dp[i-1][j-p]));
				}
				
			}
			
		}
		
	}
	
	printf("%d\n",dp[6][T]);
	
	
}
