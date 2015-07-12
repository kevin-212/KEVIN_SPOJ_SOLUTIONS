#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define pii pair<unsigned int,unsigned int>
#define ull unsigned long long int
using namespace std;
ull miN;
unsigned int u,c;
int n;
vector<pii>arr[101];
	unsigned int Q[101];
bool check[101];
int bs(unsigned int val)
{
		int low=1,high=n,mid;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(Q[mid]==val && check[mid])
					return mid;
			if(Q[mid]<=val)
				low=mid+1;
			else
				high=mid-1;

		}
		return -1;
}
void func(int index,ull sum)
{
	
	if(index==n+1)
	{
		if(miN>sum)
			miN=sum;
		return;
	}
	int sz=arr[index].size();
	for(int i=0;i<sz;i++)
	{

		u=arr[index][i].first;
		c=arr[index][i].second;
		
		int j=bs(u);
		if(j!=-1)
		{
			check[j]=false;
			
			func(index+1,sum+c);
			check[j]=true;
		}

		
	}
	return;
	
}


bool cmp(pii a,pii b)
{
	return a.second<b.second;
}
int main()
{
	
	int m,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
	
		for(int j=1;j<=m;j++)
		{
			scanf("%u %u",&u,&c);
			arr[i].push_back(pii(u,c));
		}
		sort(arr[i].begin(),arr[i].end(),cmp);
		
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		miN=1000000000000000000;
		memset(check,true,sizeof(check));
		for(int j=1;j<=n;j++)
			scanf("%d",&Q[j]);
		sort(Q+1,Q+n+1);
	
	
		func(1,0);
		if(miN==1000000000000000000)
			printf("-1\n");
		else
		printf("%llu\n",miN);
	}

	
}
