#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long int sum(long long int a, long long int b)
{
	
	
	return ((b*(b+1))/2-(a*(a-1))/2);
}
int main()
{
	int tc,k,n;
	bool check=true;
	 long long int ans;
	scanf("%d",&tc);
long long int arr[100000];
	while(tc--)
	{
		ans=0;
		check=true;
		scanf("%d %d",&n,&k);
		
		for(int i=0;i<k;i++)
		{
			scanf("%lld",&arr[i]);
		}
		if(k==0)
		{
			n=n%4;
			if(n==1 || n==2)
				printf("Mom\n");
				else
				printf("Chef\n");
				continue;
		}
		sort(arr,arr+k);
		int start=1;
		for(int i=0;i<k;i++)
		{
			ans+=sum(start,arr[i]-1);
			
			if(arr[i]<=ans){
			start=arr[i]+1;
			}
			else{
				check=false;
			break;
			}
		}
		if(check)
		ans+=sum(start,n);
		
			if(ans&1)
				printf("Mom\n");
				else
				printf("Chef\n");
	}
}
