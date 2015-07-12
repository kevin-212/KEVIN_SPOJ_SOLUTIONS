#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,ans;
	int arr[100000];
	scanf("%d",&t);
	while(t--)
	{ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		if(n&1)
		{
			for(i=0;i<n;i+=2)
			{
				ans=ans^arr[i];
			}
		}
		else
		ans=0;
		printf("%d\n",ans);
	}
}
