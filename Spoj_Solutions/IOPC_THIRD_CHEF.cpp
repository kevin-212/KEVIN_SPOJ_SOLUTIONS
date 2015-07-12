#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define piii pair<int,pii>
using namespace std;
inline void rdl(int &x)
{
	x=0;
	bool check=false;
	register int c;
	do{
		c=gc();
		if(c=='-')
		check=true;
	}while(c<48 || c>57);
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
	if(check)
	x=-x;
}
inline void rd(int &x)
{
	x=0;
	bool check=false;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}

}
inline void pd(long long int x)
{
	char c[21];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
inline void pdl(long long int x)
{
	char c[21];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
vector< vector<int > > edges;
vector<piii>graph;
int countt[200001];
bool visited[200001];
int parent[200001];
int dfs(int u)
{
	countt[u]=0;
	countt[u]++;
	visited[u]=true;
	int sz=edges[u].size(),j;
	for(int i=0;i<sz;i++)
	{
		j=edges[u][i];
		if(!visited[j])
			countt[u]+=dfs(j),parent[j]=u;
	}
	edges[u].clear();
	return countt[u];
}
int main()
{
	
	int t,n,i,k,u,v,c;
	
	rd(t);
	
	long long int ans,j;
	while(t--)
	{
		rd(n);
		fill(visited,visited+n+1,false);
		ans=0;
		edges.resize(n+1);
		k=n-1;
		for(i=0;i<k;i++)
		{
			rd(u);
			rd(v);
			rd(c);
			edges[u].push_back(v);
			edges[v].push_back(u);
			graph.push_back(piii(c,pii(u,v)));
			
		}
		sort(graph.begin(),graph.end());
	
	
		c=graph[0].first;
		u=graph[0].second.first;
		v=graph[0].second.second;
		parent[u]=u;
		dfs(u);
		countt[u]-=countt[v];
		j=countt[u];
		n=countt[v];
		
		ans=(1LL*c*j*n);
		 parent[v]=v;
		 for(i=1;i<k;i++)
		 {
		 	
		c=graph[i].first;
		u=graph[i].second.first;
		v=graph[i].second.second; 	
		if(parent[u]==v)
		{
			n=countt[u];
			while(parent[v]!=v)
			countt[v]-=n,v=parent[v];
			countt[v]-=n;
			j=countt[v];
			
			ans+=(1LL*c*j*n);
			parent[u]=u;
		}
		else
		{
			n=countt[v];
			while(parent[u]!=u)
			countt[u]-=n,u=parent[u];
			countt[u]-=n;
			j=countt[u];
			
			ans+=(1LL*c*j*n);
			parent[v]=v;
			
		}
		 	
		 	
		 }
		 graph.clear();
	pdl(ans);
	}
	
	
	
	
}
