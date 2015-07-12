#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	
	
	
	int color[501];
	int t,k,i,num,u,v,red,green;
	bool check;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&k);
		
		vector<int>graph[501];
		check=true;
		red=0,green=0;
		
		
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&num);
			for(int l=0;l<num;l++)
			{
				scanf("%d",&u);
				graph[j].push_back(u);
			}
			color[j]=-1;
		}
		for(int l=1;l<=k;l++)
		{
			if(color[l]==-1){
			
		color[l]=1;
		red++;
		queue<int>Q;
		Q.push(l);
		while(!Q.empty() && check)
		{
			u=Q.front();
			Q.pop();
			
			for(int j=0;j<graph[u].size();j++)
			{
				v=graph[u][j];
				if(color[v]==-1)
				{
					if(color[u]==1)
					color[v]=0,green++;
					else
					color[v]=1,red++;
					Q.push(v);
				}
				else if(color[u]==color[v])
				{
					check=false;
					break;
				}
			}
			
		}
	}
	}
	
		if(check){
		if(red>green)
			u=red,v=green;
		else
		u=green,v=red;
		}
		else
		u=0,v=0;
		
		printf("Case %d:%d %d\n",i,u,v);
		
		
		
		
	}
}
