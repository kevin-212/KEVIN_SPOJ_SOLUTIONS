#include<bits/stdc++.h>
using namespace std;
int main()
{
	 int arr[100001];
	 long long int arr1[100001];
	 int sum[100001];
	int n,m,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		sum[i]=0;
		arr1[i]=0;
	}

	sum[n]=0;
	arr1[n]=0;
	for(i=n-1;i>=0;i--)
	{
		sum[i]=arr[i]+sum[i+1];
		arr1[i]=(1LL*arr[i]*sum[i])+arr1[i+1];	
	}
	
	cin>>m;
	int x,y;
	long long int ans;
	while(m--)
	{
		cin>>x>>y;
		ans=arr1[x]-arr1[y+1]-(1LL*sum[y+1]*(sum[x]-sum[y+1]));
		cout<<ans<<endl;
	}
}
