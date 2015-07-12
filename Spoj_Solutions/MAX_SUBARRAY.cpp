#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,mx,sum,ans,i;
	int cur_sum,val;
	
	int arr[100001];
	cin>>t;
	while(t--)
	{
		sum=ans=cur_sum=0;
		mx=-100000;
		cin>>n;
	
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]>0)
			sum+=arr[i];
			if(arr[i]>mx)
			mx=arr[i];
		}
		if(mx<=0)
		{
			sum=ans=mx;
			
		}		
		else
		{
			
			cur_sum=0,ans=0;
			for(i=0;i<n;i++)
			{
				
				val=cur_sum+arr[i];
				if(val>0)
				cur_sum=val;
				else
				cur_sum=0;
				
				
				if(cur_sum>ans)
				ans=cur_sum;			
			}
		}
		cout<<ans<<" "<<sum<<endl;
	}
}
