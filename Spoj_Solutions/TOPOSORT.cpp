#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;


vector<int>graph[10001];
vector<int>ans;
int arrin[10001];
set<int>starter;
int count=0;


void topo()
{
	
	
	while(!starter.empty())
	{
		
		int j=*starter.begin();
		ans.push_back(j);
		count++;
		starter.erase(starter.begin());
		for(int i=0;i<graph[j].size();i++){
		
			int u=graph[j][i];
			arrin[u]--;
			if(arrin[u]==0)
			starter.insert(u);
		}
		
		
	}

}
int main()
{
	int n,m,u,v,i;
	
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;i++)
	arrin[i]=0;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		arrin[v]++;
	}
	for(i=1;i<=n;i++)
	{
		if(arrin[i]==0)
		starter.insert(i);
	}
	topo();
	if(count==n)
	{
		for(i=0;i<n;i++)
		printf("%d ",ans[i]);
	}
	else
	printf("Sandro fails.");
}
