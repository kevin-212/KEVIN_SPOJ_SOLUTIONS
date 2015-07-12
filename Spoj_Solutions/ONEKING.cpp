#include<iostream>
#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
bool cmp(pii a,pii b)
{
	return a.second<b.second;
}
int main()
{
	int tc,n,a,b,i;
	pii arr[100001];
	scanf("%d",&tc);
	while(tc--)
	{
		
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			arr[i]=pii(a,b);
		}
		sort(arr,arr+n,cmp);
		int ans=1;
		int temp=arr[0].second,l=0,temp1;
		
		for(i=1;i<n;i++)
		{
			a=arr[i].first;
			if(a>temp)
			{
				ans++;
				temp=arr[i].second;
			}
		}
		printf("%d\n",ans);
	}
}
