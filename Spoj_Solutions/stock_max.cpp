#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
long long int arr[50001];
int n;

int main()
{
	int t,i,mx,sz,start,end;
	long long int ans;
	cin>>t;
	vector<pii>dp;
while(t--)
{
	dp.clear();
	mx=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
		mx=0;
		arr[n]=0;
	for(i=n-1;i>=0;i--)
	{
		if(arr[i]>mx)
		{
		mx=arr[i];
		dp.push_back(pii(mx,i));
		}
		arr[i]+=arr[i+1];
	}
	sz=dp.size();
	start=0;
	ans=0;
	while(sz)
	{
			end=dp[sz-1].second;
			
			ans+=(1LL*dp[sz-1].first*(end-start))-(arr[start]-arr[end]);
			sz--;
			start=end+1;
					
	}
	
	cout<<ans<<endl;
}

}

