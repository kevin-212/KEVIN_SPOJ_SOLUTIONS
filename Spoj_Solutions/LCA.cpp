#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int parent[1001];
	bool check[1001];
	int tc,n,m,q,temp,ans,index=1;
	scanf("%d",&tc);
	for(;index<=tc;index++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		parent[i]=i;
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&temp);
				parent[temp]=i;
			}
		}
		scanf("%d",&q);
		printf("Case %d:\n",index);
		
		for(int i=0;i<q;i++)
		{
			
			for(int j=0;j<=n;j++)
			check[j]=false;
			scanf("%d %d",&m,&temp);
			while(parent[m]!=m)
				check[m]=true,m=parent[m];
		
		check[m]=true;
			while(check[temp]!=1)
			temp=parent[temp];
			printf("%d\n",temp);
			
		}
	}
}
		



