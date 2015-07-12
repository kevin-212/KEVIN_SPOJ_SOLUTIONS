#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,t;
	cin>>t;
	while(t--){
	
	cin>>n>>m;
	long long int arr[100001];
	memset(arr,0,sizeof arr);
	long long int mx=0;
	int i,l,r,j,count,ans;
	for(i=0;i<m;i++)
	{
		cin>>l>>r;
		count=1;
		for(j=l;j<=r;j++)
		{
			arr[j]+=count;
			count++;
			if(arr[j]>mx)
			{
				mx=arr[j];
				ans=j;
			}
		}
	}
	cout<<ans<<endl;
}
}
