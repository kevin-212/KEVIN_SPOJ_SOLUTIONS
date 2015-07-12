#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,k,i,num,lim,j;
	bool ans;
	cin>>t;
	int arr[2001];
	bool check[2001];
	while(t--)
	{
		cin>>n>>k;
		ans=false;
		for(i=0;i<n;i++)
		cin>>arr[i];
		memset(check,false,sizeof(check));
		check[0]=true;
		for(i=0;i<n;i++)
		{
			num=arr[i];
			lim=k-arr[i];
			for(j=0;j<=lim;j++)
			{
				if(check[j])
				check[j+num]=true;
			}
			if(check[k])
			{
			ans=true;
			break;
			}
			
		}
		if(ans)
		cout<<k<<endl;
		else
		{
			for(i=k;i>=0;i--)
			{
				if(check[i])
				break;
			}
			cout<<i<<endl;
		}
	}
}
