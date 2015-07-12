#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	int arr[500001];
	int m,num,x,L=1,R=0,l,r,k;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&num);
		if(num==0)
		{
			scanf("%d",&x);
			R++;
			arr[R]=x;
		}
		else if(num==1)
		{
			int ans=INT_MIN,temp,ans1;
			scanf("%d %d %d",&l,&r,&x);
			for(int i=l;i<=r;i++)
			{
				temp=arr[i]^x;
				if(temp>ans)
				{
					ans=temp;
					ans1=arr[i];
				}
			}
			printf("%d\n",ans1);
		}
		else if(num==2)
		{
			scanf("%d",&k);
			R=R-k;
		}
		else if(num==3)
		{
			int ans=0;
			scanf("%d %d %d",&l,&r,&x);
			for(int i=l;i<=r;i++)
			if(arr[i]<=x)
			ans++;
			printf("%d\n",ans);
		}
		else
		{
			scanf("%d %d %d",&l,&r,&k);
			sort(arr+l,arr+r+1);
			printf("%d\n",arr[l+k-1]);
		}
	}
}
