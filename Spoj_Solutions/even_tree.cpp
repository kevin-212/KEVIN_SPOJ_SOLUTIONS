#include<bits/stdc++.h>
using namespace std;
bool visited[101];
vector<int>arr[101];
int ans;
int  dfs(int u)
{
	int count=1;
visited[u]=true;
int sz,i,v;
sz=arr[u].size();
for(i=0;i<sz;i++)
{
	v=arr[u][i];
	if(!visited[v])
	count+=dfs(v);
}
if(!(count&1))
ans++;
return count;
}
int main()
{
	int n,m;
	cin>>n>>m;

	int u,v,i;
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	memset(visited,false,sizeof(visited));
	ans=0;
	
	dfs(1);
	cout<<ans-1<<endl;
}
