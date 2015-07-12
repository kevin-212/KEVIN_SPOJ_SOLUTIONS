#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc,n,i,j,k,temp,mx;

	map<int,int>mp;
	scanf("%d",&tc);
	while(tc--)
	{
		mx=0;
		mp.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		 scanf("%d",&temp);
		 mp[temp]++;
		 if(mx<mp[temp])
		 mx=mp[temp];
		}
		printf("%d\n",n-mx);
	}
}
